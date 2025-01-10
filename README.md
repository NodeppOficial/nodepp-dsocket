# Nodepp-DSocket
a simple chunk encoding websocket implementation

## Client
```cpp
#include <nodepp/nodepp.h>
#include <dsocket/ds.h>

using namespace nodepp;

void onMain() {

    auto client = ds::client( "ds://localhost:8000" );

    client.onConnect([=]( ds_t cli ){

        cli.onClose([=](){ process::exit(); });

        cli.onData([=]( string_t data ){
            console::log( data );
        });

        console::log("Connected");
        cli.write("Hello World!");

    });
    
}
```

## Server
```cpp
#include <nodepp/nodepp.h>
#include <dsocket/ds.h>

using namespace nodepp;

void onMain() {

    auto server = ds::server();

    server.onConnect([=]( ds_t cli ){

        cli.onClose([=](){ process::exit(); });

        cli.onData([=]( string_t data ){
            console::log( data );
        });

        console::log("Connected");
        cli.write("Hello World!");

    });

    server.listen( "localhost", 8000, [=](...){
        console::log( "-> http://localhost:8000" );
    });
    
}
```
