#include "boxcore.h"

namespace hdtoolbox
{

BoxCore::BoxCore()
{
    session = false;
    prompt = "core >>";

    /*
           (Step 4)
           Register modules into moduleMap
    */

    moduleMap.insert(
                HDTBMapItem
                ("help", HDTB_CODE_HELP)
                );

    // Add new modules below this line

    moduleMap.insert(
                HDTBMapItem
                ("machine", HDTB_CODE_MACHINE)
                );

}

void BoxCore::beginHumanInteraction()
{
    session = true;
    std::string line;
    HDTBReturnItem ri(HDTB_RETURN_BAD, HDTB_DEFAULT_MESSAGE);

    std::cout << "Initiating. Type 'exit' to end session." << std::endl;

    while(session)
    {
        // Give a prompt, and retrieve input
        std::cout << std::endl << prompt << " ";
        std::getline(std::cin, line);

        // Split input into words
        std::istringstream iss(line);
        std::vector<std::string> args{
            std::istream_iterator<std::string>{iss},
            std::istream_iterator<std::string>{}};

        // See if user just wants to exit
        if(args[0] == "exit")
        {
            session = false;
            continue;
        }

        // Add request to history
        history.push(args);

        // Process request
        ri = processRequest(args);

        // Handle ri by return code
        switch(ri.retCode)
        {
        case HDTB_RETURN_GOOD:
            // Do nothing at the moment if everything is good
            break;

        case HDTB_RETURN_BAD:
            std::cout << "[HDTB_RETURN_BAD] : Message > " << ri.message << std::endl;
            break;

        case HDTB_RETURN_EXIT:
            // Return HDTB_RETURN_EXIT from module to initiate exit
            session = false;
            break;

        default:
            break;
        }
    }

    // Exit message.
    std::cout << std::endl << "Exiting. Goodbye. :-]" << std::endl << std::endl;
}

HDTBReturnItem BoxCore::processRequest(std::vector<std::string> args)
{
    // Default return
    HDTBReturnItem ri(HDTB_RETURN_BAD, "None");

    unsigned outputControl = 0;

    // Ensure module key exists within map.
    if(moduleMap.find(args[0]) == moduleMap.end())
    {
        std::cout << "No module triggered by [" << args[0] << "] " << std::endl;
        ri.retCode = HDTB_RETURN_GOOD;
        std::cout << std::endl << "Type 'help me' to figure out what to do. " << std::endl;

    }
    else
    {
        /*
                (Step 5)
                Add module triggers here to this switch statement.

        */

        switch(moduleMap.at(args[0]))
        {
        case HDTB_CODE_HELP:

            // Set returnItem to whatever module gives us
            ri = modBox.helpModule.processRequest(args);

            /*
                    Here to break; not required for other modules.
            */
            if(ri.comm == 'M')
            {
                std::cout << std::endl << "Available modules : " << std::endl;

                // List modules [Non-Help module function]
                for(HDTBMapIterator it = moduleMap.begin();
                    it != moduleMap.end(); ++it)
                {
                    // Print off columns of 5
                    if(++outputControl % 5 == true)
                        std::cout << std::endl;

                    // Print module name
                    std::cout << std::setw(10) << it->first;
                }
            }

            std::cout << std::endl;
            break;

        case HDTB_CODE_MACHINE:
            ri = modBox.machineModule.processRequest(args);
            break;

        /*
         *          Example of adding new module
         *
        case HDTB_CODE_<NEWITEM>:
            ri = modBox.NEW_MODULE.processRequest(args);
            break;
        */

        default:
            std::cout << "Default reached in process request. Handle Error" << std::endl;
            break;
        }
    }

    return ri;
}

}

