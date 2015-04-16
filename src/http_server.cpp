#include "http_server.h"

#include <httpserver.hpp>

#include "megahttp_resource.h"
#include "account_files_resource.h"
#include "login_resource.h"

using namespace std;
using namespace httpserver;


void start_http_server()
{
    webserver server =
        create_webserver(server_port).max_threads(server_max_threads);

    megahttp_resource resource;
    account_files_resource a_resource;
    login_resource l_resource;
    server.register_resource("/", &a_resource, true);
    server.register_resource("/url", &resource, false);
    server.register_resource("/login", &l_resource, true);

    server.start(true);
}
