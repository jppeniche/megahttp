#ifndef GET_PUBLIC_NODE_LISTENER_H
#define GET_PUBLIC_NODE_LISTENER_H

#include "mega_client.h"
#include "result_listener.h"


class get_public_node_listener
    : public result_listener<std::unique_ptr<mega::MegaNode>>,
      public mega::MegaRequestListener
{
public:
    void onRequestFinish(mega::MegaApi *,
                         mega::MegaRequest *,
                         mega::MegaError *);

    std::shared_ptr<mega::MegaError> error;
};

#endif // GET_PUBLIC_NODE_LISTENER_H
