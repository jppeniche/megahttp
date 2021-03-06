/*
     This file is part of libhttpserver
     Copyright (C) 2011, 2012, 2013, 2014 Sebastiano Merlino

     This library is free software; you can redistribute it and/or
     modify it under the terms of the GNU Lesser General Public
     License as published by the Free Software Foundation; either
     version 2.1 of the License, or (at your option) any later version.

     This library is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
     Lesser General Public License for more details.

     You should have received a copy of the GNU Lesser General Public
     License along with this library; if not, write to the Free Software
     Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
     USA
*/

#include <httpserver.hpp>
#include <iostream>

using namespace httpserver;
using namespace std;

class cat_resource : public http_resource<cat_resource> {
    public:
        void render(const http_request&, http_response**);
        void set_some_data(const string &s) {data = s;}
        string data;
};

//using the render method you are able to catch each type of request you receive
void cat_resource::render(const http_request& req, http_response** res)
{
    string file = req.get_arg("file");
    cout << "file: " << file << endl;

    //it is possible to send a response initializing an http_string_response
    //that reads the content to send in response from a string.
    *res = new http_response(http_response_builder(file, 200).file_response());
}

int main()
{
    //it is possible to create a webserver passing a great number of parameters.
    //In this case we are just passing the port and the number of thread running.
    webserver ws = create_webserver(8080).max_threads(5);

    cat_resource resource;
    ws.register_resource("/", &resource, true);

    //This way we are putting the created webserver in listen. We pass true in order to have
    //a blocking call; if we want the call to be non-blocking we can just pass false to the
    //method.
    ws.start(true);
    return 0;
}
