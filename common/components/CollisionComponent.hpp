#pragma once

#include "SerializableComponent.hpp"

namespace kengine {
	class CollisionComponent : public SerializableComponent<CollisionComponent> {
	public:
		CollisionComponent(const std::function<void(kengine::GameObject &, kengine::GameObject &)> & onCollide = nullptr)
			: onCollide(onCollide) {}

		const std::string type = pmeta_nameof(CollisionComponent);
		std::function<void(kengine::GameObject &, kengine::GameObject &)> onCollide = nullptr;

	public:
		pmeta_get_class_name(CollisionComponent);
		pmeta_get_attributes();
	};
}