#include "precompiled.hpp"
#include "game/messages/server/chat_local.hpp"

message::out::chat_local_t::chat_local_t(int frame, int sender_id, const std::string& text) :
    engine::network::message::server_t(static_cast<int>(type::chat_local), frame),
    m_sender_id(sender_id),
    m_text(text)
{
}

message::out::chat_local_t::~chat_local_t() {
}

void message::out::chat_local_t::write_data(rapidjson::Writer<rapidjson::StringBuffer>& writer) const {
    writer.String("id");
    writer.Int(m_sender_id);
    writer.String("text");
    writer.String(m_text.c_str());
}

void message::out::chat_local_t::write_data(binary_writer_t& writer) const {
    writer.write_uint16(static_cast<unsigned short>(m_sender_id));
    writer.write_string(m_text);
}