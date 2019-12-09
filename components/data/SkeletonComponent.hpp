#pragma once

#include <glm/glm.hpp>
#include "vector.hpp"

#ifndef KENGINE_BONE_NAME_MAX_LENGTH
# define KENGINE_BONE_NAME_MAX_LENGTH 64
#endif

#ifndef KENGINE_MAX_MESHES_PER_MODEL
# define KENGINE_MAX_MESHES_PER_MODEL 64
#endif

#ifndef KENGINE_SKELETON_MAX_BONES
# define KENGINE_SKELETON_MAX_BONES 100
#endif

namespace kengine {
	struct SkeletonComponent {
		struct Mesh {
			glm::mat4 boneMatsBoneSpace[KENGINE_SKELETON_MAX_BONES]; // Used by shader
			glm::mat4 boneMatsMeshSpace[KENGINE_SKELETON_MAX_BONES]; // Used to get bone matrix in world space
		};
		putils::vector<Mesh, KENGINE_MAX_MESHES_PER_MODEL> meshes;
	};
}