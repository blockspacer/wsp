#include "precompiled.hpp"
#include "messages_out/body_state.hpp"

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

message::out::body_state_t::body_state_t(int frame, const std::unordered_map<int, physics_object_t::body_state_t>& state) :
    message_t(type::body_state, frame),
    m_state(state)
{
}

message::out::body_state_t::~body_state_t() {
}

void message::out::body_state_t::write_data(rapidjson::Writer<rapidjson::StringBuffer>& writer) const {
    writer.String("objects");
    writer.StartArray();
    for (auto& pair : m_state) {
        auto& id = pair.first;
        auto& state = pair.second;
        writer.StartObject();
        writer.String("id");
        writer.Int(id);
        writer.String("sleeping");
        writer.Bool(state.sleeping);
        writer.String("position");
        writer.StartArray();
        writer.Double(state.position.x);
        writer.Double(state.position.y);
        writer.Double(state.position.z);
        writer.EndArray();
        writer.String("rotation");
        writer.StartArray();
        writer.Double(state.rotation.x);
        writer.Double(state.rotation.y);
        writer.Double(state.rotation.z);
        writer.Double(state.rotation.w);
        writer.EndArray();
        writer.String("linear_speed");
        writer.StartArray();
        writer.Double(state.linear_speed.x);
        writer.Double(state.linear_speed.y);
        writer.Double(state.linear_speed.z);
        writer.EndArray();
        writer.String("angular_speed");
        writer.StartArray();
        writer.Double(state.angular_speed.x);
        writer.Double(state.angular_speed.y);
        writer.Double(state.angular_speed.z);
        writer.EndArray();
        writer.EndObject();
    }
    writer.EndArray();
}
