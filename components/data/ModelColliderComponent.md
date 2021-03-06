# [ModelColliderComponent](ModelColliderComponent.hpp)

`Component` attached to a ["model" Entity](ModelComponent.md) that describes the colliders associated with the 3D model.

## Specs

* [Reflectible](https://github.com/phisko/putils/blob/master/reflection.md)
* Serializable (POD)
* Processed by physics systems (such as the [BulletSystem](../../systems/bullet/BulletSystem.md))

## Members

### Collider type

```cpp
struct Collider {
    enum Shape {
        Box,
        Capsule,
        Cone,
        Cylinder,
        Sphere
    };

    Shape shape;
    putils::string<KENGINE_BONE_NAME_MAX_LENGTH> boneName;
    putils::Rect3f boundingBox = { {}, { 1.f, 1.f, 1.f } };
    float yaw = 0.f;
    float pitch = 0.f;
    float roll = 0.f;
};
```

The maximum length of a bone name (stored as a [putils::string](https://github.com/phisko/putils/blob/master/string.hpp)) defaults to 64, and can be adjusted by defining the `KENGINE_BONE_NAME_MAX_LENGTH` macro.

### colliders

```cpp
putils::vector<Collider, KENGINE_MAX_MODEL_COLLIDERS, vectorName> colliders;
```

The maximum number of colliders defaults to 64 and can be adjusted by defining the `KENGINE_MAX_MODEL_COLLIDERS` macro.