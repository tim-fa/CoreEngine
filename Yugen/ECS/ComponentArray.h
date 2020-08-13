//
// Created by Tim on 12.08.2020.
//

#ifndef ENGINE_COMPONENTARRAY_H
#define ENGINE_COMPONENTARRAY_H

// STL
#include <unordered_map>
#include <array>

// Local
#include "EntityManager.h"

namespace Yugen::ECS::internal
{
	class IComponentArray
	{
		public:
			IComponentArray()
			= default;

			virtual ~IComponentArray() = default;
			virtual void entityDestroyed(Entity entity) = 0;
	};

	template<typename T>
	class ComponentArray : public IComponentArray
	{
		public:
			void addComponent(Entity entity, T component)
			{
				if (mEntityToIndexMap.find(entity) != mEntityToIndexMap.end()) {
					logger.f("Component added to same entity more than once.");
				}

				// Put new entry at end and update the maps
				size_t newIndex = mSize;
				mEntityToIndexMap[entity] = newIndex;
				mIndexToEntityMap[newIndex] = entity;
				mComponentArray[newIndex] = component;
				++mSize;
			}

			void removeComponent(Entity entity)
			{
				if (mEntityToIndexMap.find(entity) == mEntityToIndexMap.end()) {
					logger.f("Removing non-existent component.");
				}

				// Copy element at end into deleted element's place to maintain density
				size_t indexOfRemovedEntity = mEntityToIndexMap[entity];
				size_t indexOfLastElement = mSize - 1;
				mComponentArray[indexOfRemovedEntity] = mComponentArray[indexOfLastElement];

				// Update map to point to moved spot
				Entity entityOfLastElement = mIndexToEntityMap[indexOfLastElement];
				mEntityToIndexMap[entityOfLastElement] = indexOfRemovedEntity;
				mIndexToEntityMap[indexOfRemovedEntity] = entityOfLastElement;

				mEntityToIndexMap.erase(entity);
				mIndexToEntityMap.erase(indexOfLastElement);

				--mSize;
			}

			T& getComponent(Entity entity)
			{
				if (mEntityToIndexMap.find(entity) == mEntityToIndexMap.end()) {
					logger.f("Retrieving non-existent component.");
				}
				return mComponentArray[mEntityToIndexMap[entity]];
			}

			void entityDestroyed(Entity entity) override
			{
				if (mEntityToIndexMap.find(entity) != mEntityToIndexMap.end()) {
					removeComponent(entity);
				}
			}

		private:
			std::array<T, MAX_ENTITIES> mComponentArray;
			std::unordered_map<Entity, size_t> mEntityToIndexMap;
			std::unordered_map<size_t, Entity> mIndexToEntityMap;
			size_t mSize{0};
	};
}

#endif //ENGINE_COMPONENTARRAY_H
