#include <memory>
#include "graphedge.h"
#include "graphnode.h"



GraphNode::GraphNode(int id)
{
    _id = id;
    _chatBot = new ChatBot();
}

GraphNode::~GraphNode(){}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
//// 
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    // QUESTION: transfer ownership of lvalues    
    *_chatBot = std::move(chatbot);
    _chatBot->SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(*_chatBot));
    _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}