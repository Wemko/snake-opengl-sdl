#pragma once

#include <glm/glm.hpp>

class GameObject {
    public:
        GameObject();

        glm::vec3 getTransform();
        void setTransform(float x, float y, float z);

        glm::vec3 getScale();
        void setScale(float x, float y, float z);

        glm::vec3 getRotation();
        void setRotation(float x, float y, float z);

    private:
        glm::vec3 transform;
        glm::vec3 scale;
        glm::vec3 rotation;
};