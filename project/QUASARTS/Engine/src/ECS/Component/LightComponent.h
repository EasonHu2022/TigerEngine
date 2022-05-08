#pragma once

// Library includes:

#include <string>

// Local includes:
#include "ECS/ECS-Common.h"
#include "glm/glm.hpp"
#include "Core/StaticReflection.h"
namespace Engine {
    enum class LightType
    {
        def = 0,
        spot,
        parallel,
        point,
    }; 

    struct QS_API LightComponent {
       
        glm::vec3 ambient = {0.2f,0.2f,0.2f};
        glm::vec3 diffuse = { 0.2f,0.2f,0.2f };
        glm::vec3 specular = { 0.2f,0.2f,0.2f };   
        LightType type = LightType::def;
        DEFINE_PROPERTIES(
            (glm::vec4) ambient1,
            (glm::vec4) diffuse1,
            (glm::vec4) specular1        
        )
    };



    // Input stream operator:
    inline std::istream & operator >> (std::istream &inStream, LightComponent &light) {
        int light_type;
        inStream >> light_type;
        if (light_type == 1) { light.type = LightType::spot; }
        else if (light_type == 2) { light.type = LightType::parallel; }
        else if (light_type == 3) { light.type = LightType::point; }
        else { light.type = LightType::def; }
        
        inStream
        >> light.ambient[0] >> light.ambient[1] >> light.ambient[2]
        >> light.diffuse[0] >> light.diffuse[1] >> light.diffuse[2]
        >> light.specular[0] >> light.specular[1] >> light.specular[2];

        return inStream;
    }
            
    // Output stream operator:
    inline std::ostream & operator << (std::ostream &outStream, const LightComponent &light) {
        if (light.type == LightType::spot) { outStream << 1; }
        else if (light.type == LightType::parallel) { outStream << 2; }
        else if (light.type == LightType::point) { outStream << 3; }
        else { outStream << 0; }

        outStream
        << " " << light.ambient[0] << " " << light.ambient[1] << " " << light.ambient[2]
        << " " << light.diffuse[0] << " " << light.diffuse[1] << " " << light.diffuse[2]
        << " " << light.specular[0] << " " << light.specular[1] << " " << light.specular[2];
        
        return outStream;
    }
}