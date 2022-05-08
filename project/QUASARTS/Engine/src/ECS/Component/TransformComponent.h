#pragma once

// Local includes:
#include "ECS/ECS-Common.h"
#include "glm/glm.hpp"
#include "glm/ext.hpp"
#include "Core/StaticReflection.h"


namespace Engine {
    struct QS_API TransformComponent {
        int operation = 0;
        DEFINE_PROPERTIES(
            (glm::vec3) position,
            (glm::vec3) rotation,
            (glm::vec3) scale
            )
    };

    // Input stream operator:
    inline std::istream & operator >> (std::istream &inStream, TransformComponent &transform) {
        inStream
        >> transform.position[0] >> transform.position[1] >> transform.position[2]
        >> transform.rotation[0] >> transform.rotation[1] >> transform.rotation[2]
        >> transform.scale[0] >> transform.scale[1] >> transform.scale[2];

        return inStream;
    }
            
    // Output stream operator:
    inline std::ostream & operator << (std::ostream &outStream, const TransformComponent &transform) {
        outStream
        << transform.position[0] << " " << transform.position[1] << " " << transform.position[2]
        << " " << transform.rotation[0] << " " << transform.rotation[1] << " " << transform.rotation[2]
        << " " << transform.scale[0] << " " << transform.scale[1] << " " << transform.scale[2];
        
        return outStream;
    }

}