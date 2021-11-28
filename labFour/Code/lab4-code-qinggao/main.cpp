#include <emscripten/emscripten.h>
#include <emscripten/websocket.h>
#include <stdio.h>

//Emscripten WebSocket Open Event
EM_BOOL onopen(int eventType, const EmscriptenWebSocketOpenEvent *websocketEvent, void *userData) {
    puts("onopen");

    EMSCRIPTEN_RESULT result;
    result = emscripten_websocket_send_utf8_text(websocketEvent->socket, "Hello server! I am Qing~");
    if (result) {
        printf("Failed to emscripten_websocket_send_utf8_text(): %d\n", result);
    }
    return EM_TRUE;
}
//Emscripten WebSocket Error Event
EM_BOOL onerror(int eventType, const EmscriptenWebSocketErrorEvent *websocketEvent, void *userData) {
    puts("onerror");

    return EM_TRUE;
}
//Emscripten WebSocket Close Event
EM_BOOL onclose(int eventType, const EmscriptenWebSocketCloseEvent *websocketEvent, void *userData) {
    puts("onclose");

    return EM_TRUE;
}
//Emscripten WebSocket Message Event
EM_BOOL onmessage(int eventType, const EmscriptenWebSocketMessageEvent *websocketEvent, void *userData) {
    puts("onmessage");
    if (websocketEvent->isText) {
        // For only ascii chars.
        printf("message: %s\n", websocketEvent->data);
    }

    EMSCRIPTEN_RESULT result;
    result = emscripten_websocket_close(websocketEvent->socket, 1000, "no reason");
    if (result) {
        printf("Failed to emscripten_websocket_close(): %d\n", result);
    }
    return EM_TRUE;
}

int main() {
    if (!emscripten_websocket_is_supported()) {
        return 0;
    }
    //Emscripten WebSocket Create Attributes
    EmscriptenWebSocketCreateAttributes ws_attrs = {
        "ws://localhost:5500/",
        NULL,
        EM_TRUE
    };

    EMSCRIPTEN_WEBSOCKET_T ws = emscripten_websocket_new(&ws_attrs);
    emscripten_websocket_set_onopen_callback(ws, NULL, onopen);
    emscripten_websocket_set_onerror_callback(ws, NULL, onerror);
    emscripten_websocket_set_onclose_callback(ws, NULL, onclose);
    emscripten_websocket_set_onmessage_callback(ws, NULL, onmessage);
}
