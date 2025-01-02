#include <nodepp/nodepp.h>
#include <hsocket/hs.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain() {

    auto client = hs::client( "hs://localhost:8000" );
    auto cin    = fs::std_input(); 

    client.onConnect([=]( hs_t cli ){

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