//
// Created by Tim on 13.08.2020.
//

#ifndef ENGINE_COMPONENTMANAGER_H
#define ENGINE_COMPONENTMANAGER_H

#include "ComponentArray.h"

namespace Yugen::ECS::internal
{
	class ComponentManager
	{
		public:
			template<typename T>
			void registerComponent()
			{
				auto key = typeid(T).name();

				if (mComponentTypes.find(key) != mComponentTypes.end()) {
					logger.f("Registering component type '{}' more than once.", key);
				}

				// Add this component type to the component type map
				mComponentTypes.insert({key, mNextComponentType});

				// Create a ComponentArray pointer and add it to the component arrays map
				mComponentArrays.insert({key, std::make_shared<ComponentArray<T>>()});

				// Increment the value so that the next component registered will be different
				++mNextComponentType;
			}

			template<typename T>
			ComponentType getComponentType()
			{
				auto key = typeid(T).name();

				if (mComponentTypes.find(key) == mComponentTypes.end()) {
					logger.f("Component '{}' not registered before use.", key);
				}

				// Return this component's type - used for creating signatures
				return mComponentTypes[key];
			}

			template<typename T>
			void addComponent(Entity entity, T component)
			{
				// Add a component to the array for an entity
				getComponentArray<T>()->insertData(entity, component);
			}

			template<typename T>
			void removeComponent(Entity entity)
			{
				// Remove a component from the array for an entity
				getComponentArray<T>()->removeData(entity);
			}

			template<typename T>
			T& getComponent(Entity entity)
			{
				// Get a reference to a component from the array for an entity
				return getComponentArray<T>()->getData(entity);
			}

			void entityDestroyed(Entity entity)
			{
				// Notify each component array that an entity has been destroyed
				// If it has a component for that entity, it will remove it
				for (auto const& pair : mComponentArrays) {
					auto const& component = pair.second;

					component->entityDestroyed(entity);
				}
			}

		private:
			// Map from type string pointer to a component type
			std::unordered_map<const char*, ComponentType> mComponentTypes{};

			// Map from type string pointer to a component array
			std::unordered_map<const char*, std::shared_ptr<IComponentArray>> mComponentArrays{};

			// The component type to be assigned to the next registered component - starting at 0
			ComponentType mNextComponentType{};

			template<typename T>
			std::shared_ptr<ComponentArray<T>> getComponentArray()
			{
				auto key = typeid(T).name();

				if (mComponentTypes.find(key) == mComponentTypes.end()) {
					logger.f("Component '{}' not registered before use.", key);
				}

				return std::static_pointer_cast<ComponentArray<T>>(mComponentArrays[key]);
			}
	};
}

#endif //ENGINE_COMPONENTMANAGER_H
