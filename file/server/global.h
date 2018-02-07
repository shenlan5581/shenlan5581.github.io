#pragma once

class Global {
public:
    static Global& Instance(){
        static Global inst;
        return inst;
    }

public:
    std::string root_dir;
    uint32_t port;
    uint32_t max_user;
};

