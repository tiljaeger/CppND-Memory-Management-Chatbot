#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>
#include <iostream>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////
    // copy constructor
    Chatbot (const Chatbot& source);
    // copy assignment operator
    Chatbot &operator=(const Chatbot& source);
    // move constructor
    Chatbot (Chatbot&& source);
    // move assignmentoperator
    Chatbot &operator=(Chatbot&& source);


    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    // QUESTION?: move ownership of _chatLogic to chatbot
    // QUESTION: not using move constrictor as the methd is called within chatLogic instance itselt?
    void SetChatLogicHandle(ChatLogic *chatLogic) {_chatLogic = chatLogic;}
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */