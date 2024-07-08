#include "libentity.hpp"

static int l_transform_get_pos(lua::State* L) {
    if (auto entity = get_entity(L, 1)) {
        return lua::pushvec3_arr(L, entity->getTransform().pos);
    }
    return 0;
}

static int l_transform_set_pos(lua::State* L) {
    if (auto entity = get_entity(L, 1)) {
        entity->getTransform().setPos(lua::tovec3(L, 2));
    }
    return 0;
}

static int l_transform_get_size(lua::State* L) {
    if (auto entity = get_entity(L, 1)) {
        return lua::pushvec3_arr(L, entity->getTransform().size);
    }
    return 0;
}

static int l_transform_set_size(lua::State* L) {
    if (auto entity = get_entity(L, 1)) {
        entity->getTransform().setSize(lua::tovec3(L, 2));
    }
    return 0;
}

static int l_transform_get_rot(lua::State* L) {
    if (auto entity = get_entity(L, 1)) {
        return lua::pushmat4(L, entity->getTransform().rot);
    }
    return 0;
}

static int l_transform_set_rot(lua::State* L) {
    if (auto entity = get_entity(L, 1)) {
        entity->getTransform().setRot(lua::tomat4(L, 2));
    }
    return 0;
}

const luaL_Reg transformlib [] = {
    {"get_pos", lua::wrap<l_transform_get_pos>},
    {"set_pos", lua::wrap<l_transform_set_pos>},
    {"get_size", lua::wrap<l_transform_get_size>},
    {"set_size", lua::wrap<l_transform_set_size>},
    {"get_rot", lua::wrap<l_transform_get_rot>},
    {"set_rot", lua::wrap<l_transform_set_rot>},
    {NULL, NULL}
};
