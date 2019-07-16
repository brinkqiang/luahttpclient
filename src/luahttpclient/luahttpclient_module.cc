
// Copyright (c) 2018 brinkqiang (brink.qiang@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "luahttpclient_module.h"
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <sstream>

static int post(lua_State *L)
{
    const std::string url(lua_tostring(L, -1));

    try
    {
        curlpp::Cleanup myCleanup;

        curlpp::Easy myRequest;
        myRequest.setOpt(new curlpp::options::Url(url));

        curlpp::Forms formParts;
        //formParts.push_back(new curlpp::FormParts::Content("name1", "value1"));
        //formParts.push_back(new curlpp::FormParts::Content("name2", "value2"));
        myRequest.setOpt(new curlpp::options::HttpPost(formParts));

        std::stringstream os;
        curlpp::options::WriteStream ws(&os);
        myRequest.setOpt(ws);
        myRequest.perform();

        std::string strRequest = os.str();
        lua_pushlstring(L, strRequest.c_str(), strRequest.size());
    }
    catch (curlpp::RuntimeError &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (curlpp::LogicError &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 1;
}

static int get(lua_State *L)
{
    const std::string url(lua_tostring(L, -1));

    try
    {
        curlpp::Cleanup myCleanup;

        curlpp::Easy myRequest;
        myRequest.setOpt(new curlpp::options::Url(url));
 

        curlpp::Forms formParts;
        //formParts.push_back(new curlpp::FormParts::Content("name1", "value1"));
        //formParts.push_back(new curlpp::FormParts::Content("name2", "value2"));
        myRequest.setOpt(new curlpp::options::HttpGet(true));

        std::stringstream os;
        curlpp::options::WriteStream ws(&os);
        myRequest.setOpt(ws);
        myRequest.perform();

        std::string strRequest = os.str();
        lua_pushlstring(L, strRequest.c_str(), strRequest.size());
    }
    catch (curlpp::RuntimeError &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (curlpp::LogicError &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 1;
}

static const struct luaL_Reg lib[] = {
    {"post", post},
    {"get", get},
    {NULL, NULL}
};

LUAMOD_API int luaopen_luahttpclient(lua_State* L)
{
    luaL_newlib(L, lib);
    return 1;
}

LUAMOD_API int require_luahttpclient(lua_State* L)
{
    luaL_requiref(L, "luahttpclient", luaopen_luahttpclient, 0);
    printf("lua module: require luahttpclient\n");
    return 1;
}