# luahttpclient

Copyright (c) 2013-2018 brinkqiang (brink.qiang@gmail.com)

[![luahttpclient](https://img.shields.io/badge/brinkqiang-luahttpclient-blue.svg?style=flat-square)](https://github.com/brinkqiang/luahttpclient)
[![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](https://github.com/brinkqiang/luahttpclient/blob/master/LICENSE)
[![blog](https://img.shields.io/badge/Author-Blog-7AD6FD.svg)](https://brinkqiang.github.io/)
[![Open Source Love](https://badges.frapsoft.com/os/v3/open-source.png)](https://github.com/brinkqiang)
[![GitHub stars](https://img.shields.io/github/stars/brinkqiang/luahttpclient.svg?label=Stars)](https://github.com/brinkqiang/luahttpclient) 
[![GitHub forks](https://img.shields.io/github/forks/brinkqiang/luahttpclient.svg?label=Fork)](https://github.com/brinkqiang/luahttpclient)

## Build status
| [Linux][lin-link] | [Mac][mac-link] | [Windows][win-link] |
| :---------------: | :----------------: | :-----------------: |
| ![lin-badge]      | ![mac-badge]       | ![win-badge]        |

[lin-badge]: https://github.com/brinkqiang/luahttpclient/workflows/linux/badge.svg "linux build status"
[lin-link]:  https://github.com/brinkqiang/luahttpclient/actions/workflows/linux.yml "linux build status"
[mac-badge]: https://github.com/brinkqiang/luahttpclient/workflows/mac/badge.svg "mac build status"
[mac-link]:  https://github.com/brinkqiang/luahttpclient/actions/workflows/mac.yml "mac build status"
[win-badge]: https://github.com/brinkqiang/luahttpclient/workflows/win/badge.svg "win build status"
[win-link]:  https://github.com/brinkqiang/luahttpclient/actions/workflows/win.yml "win build status"

## env
install cmake

## Intro
luahttpclient
```lua
local luahttpclient = require("luahttpclient")
local msg = {wd = "http"}

local ret = luahttpclient.post("http://www.baidu.com", msg)
print(ret)

local ret2 = luahttpclient.get("http://baidu.com")
print(ret2)
```
## Contacts
[![Join the chat](https://badges.gitter.im/brinkqiang/luahttpclient/Lobby.svg)](https://gitter.im/brinkqiang/luahttpclient)

## Thanks
