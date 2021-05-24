#include "GameObject.h"

GameObject::GameObject() {
    transform = glm::vec3(0 ,0, 0);
    rotation = glm::vec3(0 ,0, 0);
    scale = glm::vec3(1 ,1, 1);
}

void GameObject::setTransform(float x, float y, float z) {
    transform = glm::vec3(x,y,z);
};
glm::vec3 GameObject::getTransform(){
    return transform;
};

void  GameObject::setScale(float x, float y, float z){
    scale = glm::vec3(x,y,z);
};
glm::vec3 GameObject::getScale(){
    return scale;
};

void GameObject::setRotation(float x, float y, float z){
    rotation = glm::vec3(x,y,z);
};
glm::vec3 GameObject::getRotation(){
    return rotation;
};