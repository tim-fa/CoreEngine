#pragma once
//
// Created by Tim on 13.08.2020.
//

#ifndef ENGINE_SYSTEMMANAGER_H
#define ENGINE_SYSTEMMANAGER_H

// STL
#include <set>

// Local
#include "ComponentManager.h"

namespace Yugen::ECS::internal
{
	class System
	{
		public:
			std::set<Entity> mEntities;
	};

	class SystemManager
	{
		public:
			template<typename T>
			std::shared_ptr<T> registerSystem()
			{
				auto key = typeid(T).name();

				if (mSystems.find(key) != mSystems.end()) {
					logger.f("Registering system '{}' more than once.", key);
				}

				// Create a pointer to the system and return it so it can be used externally
				auto system = std::make_shared<T>();
				mSystems.insert({key, system});
				return system;
			}

			template<typename T>
			void setSignature(Signature signature)
			{
				auto key = typeid(T).name();

				if (mSystems.find(key) == mSystems.end()) {
					logger.f("System '{}' used before registered.", key);
				}

				// Set the signature for this system
				mSignatures.insert({key, signature});
			}

			void entityDestroyed(Entity entity)
			{
				// Erase a destroyed entity from all system lists
				// mEntities is a set so no check needed
				for (auto const& pair : mSystems) {
					auto const& system = pair.second;
					system->mEntities.erase(entity);
				}
			}

			void entitySignatureChanged(Entity entity, Signature entitySignature)
			{
				// Notify each system that an entity's signature changed
				for (auto const& pair : mSystems) {
					auto const& type = pair.first;
					auto const& system = pair.second;
					auto const& systemSignature = mSignatures[type];

					// Entity signature matches system signature - insert into set
					if ((entitySignature & systemSignature) == systemSignature) {
						system->mEntities.insert(entity);
					}
						// Entity signature does not match system signature - erase from set
					else {
						system->mEntities.erase(entity);
					}
				}
			}

		private:
			std::unordered_map<const char*, Signature> mSignatures{};
			std::unordered_map<const char*, std::shared_ptr<System>> mSystems{};
	};
}

#endif //ENGINE_SYSTEMMANAGER_H
