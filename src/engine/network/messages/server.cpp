#include "precompiled.hpp"
#include "engine/network/message/server.hpp"

engine::network::message::server_t::server_t(int type, int frame) :
    m_type(type),
    m_frame(frame)
{
}

engine::network::message::server_t::~server_t() {
}

void engine::network::message::server_t::write(rapidjson::Writer<rapidjson::StringBuffer>& writer) const {
    writer.StartObject();
    writer.String("type");
    writer.Int(static_cast<int>(m_type));
    writer.String("data");
    writer.StartObject();
    writer.String("frame");
    writer.Int(m_frame);
    write_data(writer);
    writer.EndObject();
    writer.EndObject();
}

void engine::network::message::server_t::write(binary_writer_t& writer) const {
    writer.write_uint8(static_cast<unsigned char>(m_type));
    writer.write_uint32(static_cast<unsigned int>(m_frame));
    write_data(writer);
}