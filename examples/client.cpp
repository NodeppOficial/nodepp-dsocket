#include <nodepp/nodepp.h>
#include <dsocket/ds.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain() {

    auto client = ds::client( "ds://localhost:8000" );
    auto cin    = fs::std_input(); 

    client.onConnect([=]( ds_t cli ){

        cli.onClose([=](){ process::exit(); });

        cin.onData([=]( string_t data ){
            cli.write( data );
        });

        cli.onData([=]( string_t data ){
            console::log( data );
        });

        console::log("Connected");

    });
    
    stream::pipe( cin );

}