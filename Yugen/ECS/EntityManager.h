//
// Created by Tim on 12.08.2020.
//

#ifndef ENGINE_ENTITYMANAGER_H
#define ENGINE_ENTITYMANAGER_H

// Library
#include "Log/Logger.h"

// STL
#include <cstdint>
#include <bitset>
#include <queue>

using Entity = uint32_t;
const Entity MAX_ENTITIES = 5000;
using ComponentType = std::uint8_t;
const ComponentType MAX_COMPONENTS = 32;
using Signature = std::bitset<MAX_COMPONENTS>;

namespace Yugen::ECS::internal
{
	static Logger logger("EntityComponentSystem");

	class EntityManager
	{
		public:
			EntityManager()
			{
				for (Entity entity = 0; entity < MAX_ENTITIES; ++entity) {
					mAvailableEntities.push(entity);
				}
			}

			Entity createEntity()
			{
				if (mLivingEntityCount >= MAX_ENTITIES) {
					logger.f("Too many entities in existence.");
				}
				Entity id = mAvailableEntities.front();
				mAvailableEntities.pop();
				++mLivingEntityCount;

				return id;
			}

			void destroyEntity(Entity entity)
			{
				if (entity >= MAX_ENTITIES) {
					logger.f("Entity out of range.");
				}

				mSignatures[entity].reset();
				mAvailableEntities.push(entity);
				--mLivingEntityCount;
			}

			void setSignature(Entity entity, Signature signature)
			{
				if (entity >= MAX_ENTITIES) {
					logger.f("Entity out of range.");
				}
				mSignatures[entity] = signature;
			}

			Signature getSignature(Entity entity)
			{
				if (entity >= MAX_ENTITIES) {
					logger.f("Entity out of range.");
				}
				return mSignatures[entity];
			}

		private:
			std::queue<Entity> mAvailableEntities{};
			std::array<Signature, MAX_ENTITIES> mSignatures{};
			uint32_t mLivingEntityCount{};
	};
}

#endif //ENGINE_ENTITYMANAGER_H
