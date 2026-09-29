#pragma once

class LED
{
public:
    LED() : _state(false) {}

    void set_state(bool on);
    bool get_state() const;

private:
    bool _state;
};
