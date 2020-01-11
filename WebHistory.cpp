#include "WebHistory.hpp"

WebHistory::WebHistory()
{
    // Does nothing.
}

WebHistory::WebHistory(std::string historyText)
{
	// history = url timestamp | url timestamp | url timestamp...
    // urls are string and timestamps are non-negative integers.
    std::string delimiter = " | ";

	std::string tabInfo;
    std::string url;
    std::string timestamp;
    size_t pos = 0;

    while (true)
	{
        pos = historyText.find(delimiter);

        bool breakTheLoop = (pos == std::string::npos);

        tabInfo = historyText.substr(0, pos);
        historyText.erase(0, pos + delimiter.length());

        pos = tabInfo.find(" ");
        
        url = tabInfo.substr(0, pos);
        timestamp = tabInfo.substr(pos + 1, tabInfo.length() - pos);

		Node<Tab> *newPage = new Node<Tab>(Tab(url, std::atoi(timestamp.c_str())), NULL, NULL);
        insertInOrder(newPage);

        if (breakTheLoop)
		{
			break;
		}
    }
}

void WebHistory::printHistory()
{
	std::cout << "Your web history:" << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
	std::cout << std::endl;
	if (history.getHead()->next == history.getTail())
	{
		std::cout << "History is empty." << std::endl;
		std::cout << std::endl;
	}
	else
	{
		Node<Tab> *node = history.getFirstNode();
		
		while (node != history.getTail())
		{
		    std::cout << "Page: " << node->element.getUrl() << std::endl;
			std::cout << "Last Visited: " << node->element.getTimestamp() << std::endl;
			std::cout << std::endl;
		    node = node->next;
		}
	}
	std::cout << "------------------------------------------------" << std::endl;
	std::cout << std::endl;
}

WebHistory::WebHistory(std::string url, int timestamp)
{
	// TODO
	Tab new_tab;
	new_tab.setTimestamp(timestamp);
	new_tab.setUrl(url);
	history.insertAtTheEnd(*new_tab);
}

WebHistory::~WebHistory()
{
	// TODO
	history.~LinkedList();
}

void WebHistory::insertInOrder(Node<Tab> *newPage)
{
	// TODO
	int timestamp = newPage->element.getTimestamp();
	Node<Tab> *current = history.getFirstNode();
	if(!current->next){
		history.insertAtTheEnd(newPage->element);
	}
	else{
			while(current->next){
			if(current->element.getTimestamp <= timestamp){
				history.insertAfterGivenNode(newPage->element, current->prev);
				break;
			}
			current = current->next;
		}
	}
}

void WebHistory::goToPage(std::string url, int timestamp)
{
	// TODO
	Tab new_tab;
	new_tab.setTimestamp(timestamp); 
	new_tab.setUrl(url);
	Node<Tab> *current = history.getFirstNode();
	if(!current->next){
		history.insertAtTheEnd(new_tab);
	}
	else{
		while(current->next){
			if(current->element.getTimestamp() <= timestamp){
				history.insertAfterGivenNode(newPage->element, current->prev);
				break;
			}
			current =current->next;
		}
	}
}

void WebHistory::clearHistory()
{
	// TODO
	history.removeAllNodes();
}

void WebHistory::clearHistory(int timestamp)
{
	// TODO
	Node<Tab> *current = history.getHead()->next;
	while(current->next){
		current =  current->next;
		if(current->prev->element.getTimestamp()<= timestamp){
			history.removeNode(current->prev);
		}
	}
}

WebHistory WebHistory::operator+(const WebHistory &rhs) const
{
	// TODO
	WebHistory new_wehistory; 

}

int WebHistory::timesVisited(std::string pageName)
{
	// BONUS
}

std::string WebHistory::mostVisited()
{
	// BONUS
}