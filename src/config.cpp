#include "config.h"

#include <megaapi.h>

using namespace std;
using namespace mega;
using namespace logging;


const int server_port = 8080;
const int server_max_threads = 2;

const string log_file = "megahttp.log";
// Types of messages that should be logged
logger::logged_types_map logged_types
{
    // log messages from MEGA SDK according to mega_log_level
    { msg_type::mega_msg, true },
    // variables from HTTP request
    { msg_type::request_info, true },
    // path of login HTTP request
    { msg_type::login_request_path, true },
    // error HTTP server returns to client
    { msg_type::response_error, true },
    // info about requested files
    { msg_type::file_info, true },
    // streaming finish
    { msg_type::response_status, true },
    // download start/finish, error
    { msg_type::download_status, true },

    // chunks returned to HTTP client (a lot of output)
    { msg_type::response_data, false },
    // chunks downloaded from MEGA    (a lot of output)
    { msg_type::download_data, false },
    // source location in mega_msg
    { msg_type::mega_msg_source_location, false },
};
int mega_log_level = MegaApi::LOG_LEVEL_INFO;

/* Time to wait before checking the state again */
const auto mega_request_sleep = chrono::milliseconds(200);
const auto http_response_sleep = chrono::milliseconds(200);