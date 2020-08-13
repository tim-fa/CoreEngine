#pragma once
//
// Created by Tim on 13.08.2020.
//

#ifndef ENGINE_ECSMANANGER_H
#define ENGINE_ECSMANANGER_H

// Local
#include "SystemManager.h"

namespace Yugen::ECS
{
	class Coordinator
	{
		public:
			Coordinator()
			{
				// Create pointers to each manager
				mComponentManager = std::make_unique<internal::ComponentManager>();
				mEntityManager = std::make_unique<internal::EntityManager>();
				mSystemManager = std::make_unique<internal::SystemManager>();
			}


			// Entity methods
			Entity createEntity()
			{
				return mEntityManager->createEntity();
			}

			void destroyEntity(Entity entity)
			{
				mEntityManager->destroyEntity(entity);

				mComponentManager->entityDestroyed(entity);

				mSystemManager->entityDestroyed(entity);
			}


			// Component methods
			template<typename T>
			void RegisterComponent()
			{
				mComponentManager->registerComponent<T>();
			}

			template<typename T>
			void AddComponent(Entity entity, T component)
			{
				mComponentManager->addComponent<T>(entity, component);

				auto signature = mEntityManager->getSignature(entity);
				signature.set(mComponentManager->getComponentType<T>(), true);
				mEntityManager->setSignature(entity, signature);

				mSystemManager->entitySignatureChanged(entity, signature);
			}

			template<typename T>
			void RemoveComponent(Entity entity)
			{
				mComponentManager->removeComponent<T>(entity);

				auto signature = mEntityManager->getSignature(entity);
				signature.set(mComponentManager->getComponentType<T>(), false);
				mEntityManager->setSignature(entity, signature);

				mSystemManager->entitySignatureChanged(entity, signature);
			}

			template<typename T>
			T& getComponent(Entity entity)
			{
				return mComponentManager->getComponent<T>(entity);
			}

			template<typename T>
			ComponentType GetComponentType()
			{
				return mComponentManager->getComponentType<T>();
			}


			// System methods
			template<typename T>
			std::shared_ptr<T> registerSystem()
			{
				return mSystemManager->registerSystem<T>();
			}

			template<typename T>
			void SetSystemSignature(Signature signature)
			{
				mSystemManager->setSignature<T>(signature);
			}

		private:
			std::unique_ptr<internal::ComponentManager> mComponentManager;
			std::unique_ptr<internal::EntityManager> mEntityManager;
			std::unique_ptr<internal::SystemManager> mSystemManager;
	};
}

#endif //ENGINE_ECSMANANGER_H
