#pragma once

#include "engine/network/message/server.hpp"

#include "game/messages/types.hpp"

namespace message::out {
class login_t : public engine::network::message::server_t {
private:
    int m_frame;

protected:
    virtual void write_data(rapidjson::Writer<rapidjson::StringBuffer>& writer) const override;
    virtual void write_data(binary_writer_t& writer) const override;

public:
    login_t(int frame);
    virtual ~login_t() override;
};
}