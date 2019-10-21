#include "precompiled.hpp"
#include "messages_out/body_create.hpp"

message::out::body_create_t::body_create_t(int frame, const physics_object_t::body_t& body) :
    message_t(type::body_create, frame),
    m_body(body)
{
}

message::out::body_create_t::~body_create_t() {
}

void message::out::body_create_t::write_data(rapidjson::Writer<rapidjson::StringBuffer>& writer) const {
    const auto& position = m_body.get_state().position;
    const auto& rotation = m_body.get_state().rotation;
    const auto& rotation_factor = m_body.get_rotation_factor();
    writer.String("id");
    writer.Int(m_body.get_id());
    writer.String("moving");
    writer.Bool(m_body.is_moving());
    writer.String("position");
    writer.StartArray();
    writer.Double(position.x);
    writer.Double(position.y);
    writer.Double(position.z);
    writer.EndArray();
    writer.String("rotation");
    writer.StartArray();
    writer.Double(rotation.x);
    writer.Double(rotation.y);
    writer.Double(rotation.z);
    writer.Double(rotation.w);
    writer.EndArray();
    writer.String("rotation_factor");
    writer.StartArray();
    writer.Double(rotation_factor.x);
    writer.Double(rotation_factor.y);
    writer.Double(rotation_factor.z);
    writer.EndArray();
    writer.String("shapes");
    writer.StartArray();
    for (const auto& shape : m_body.get_shapes()) {
        writer.StartObject();
        writer.String("type");
        writer.Int(static_cast<int>(shape->type));
        writer.String("position");
        writer.StartArray();
        writer.Double(shape->position.x);
        writer.Double(shape->position.y);
        writer.Double(shape->position.z);
        writer.EndArray();
        writer.String("rotation");
        writer.StartArray();
        writer.Double(shape->rotation.x);
        writer.Double(shape->rotation.y);
        writer.Double(shape->rotation.z);
        writer.Double(shape->rotation.w);
        writer.EndArray();
        writer.String("size");
        writer.StartArray();
        writer.Double(shape->size.x);
        writer.Double(shape->size.y);
        writer.Double(shape->size.z);
        writer.EndArray();
        writer.EndObject();
    }
    writer.EndArray();
}
