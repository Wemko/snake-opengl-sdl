#include "GameObject.h"

GameObject::GameObject() {
    transform = glm::vec3(0 ,0, 0);
    rotation = glm::vec3(0 ,0, 0);
    scale = glm::vec3(0 ,0, 0);
}

void GameObject::setTransform(glm::vec3 t) {
    transform = t;
};
glm::vec3 GameObject::getTransform(){
    return transform;
};

void  GameObject::setScale(glm::vec3 s){
    scale = s;
};
glm::vec3 GameObject::getScale(){
    return scale;
};

void GameObject::setRotation(glm::vec3 r){
    rotation = r;
};
glm::vec3 GameObject::getRotation(){
    return rotation;
};