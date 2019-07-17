
local luahttpclient = require("luahttpclient")
local msg = {wd = "http"}

local ret = luahttpclient.post("http://www.baidu.com", msg)
print(ret)

local ret2 = luahttpclient.get("http://baidu.com")
print(ret2)