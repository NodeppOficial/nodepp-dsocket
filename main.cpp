#include <nodepp/nodepp.h>
#include <hsocket/hs.h>
#include <nodepp/fs.h>

using namespace nodepp;

void onMain() {

    event_t<> event;

    event  .on([=](){ console::log("on");   });
    event.once([=](){ console::log("once"); });

    event.emit();
    event.emit();
    event.emit();
    event.emit();
    event.emit();
    
}