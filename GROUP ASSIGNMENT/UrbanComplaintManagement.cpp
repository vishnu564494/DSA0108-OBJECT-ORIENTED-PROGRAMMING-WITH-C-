#include <iostream>
#include <string>

using namespace std;

// ==================== CITIZEN CLASS ====================
class Citizen
{
private:
    int citizenId;
    string name;
    string phone;

public:
    Citizen()
    {
        citizenId = 0;
        name = "";
        phone = "";
    }

    Citizen(int id, string n, string p)
    {
        citizenId = id;
        name = n;
        phone = p;
    }

    void displayCitizen()
    {
        cout << "\nCitizen ID: " << citizenId;
        cout << "\nName: " << name;
        cout << "\nPhone: " << phone << endl;
    }

    int getCitizenId()
    {
        return citizenId;
    }

    string getName()
    {
        return name;
    }
};


// ==================== ABSTRACT BASE CLASS ====================
class Complaint
{
protected:
    int complaintId;
    string citizenName;
    string description;
    string location;
    string department;
    string status;

    static int totalComplaints;

public:

    // Default Constructor
    Complaint()
    {
        complaintId = 0;
        citizenName = "";
        description = "";
        location = "";
        department = "Not Assigned";
        status = "Registered";
    }

    // Parameterized Constructor
    Complaint(int id, string name, string desc, string loc)
    {
        complaintId = id;
        citizenName = name;
        description = desc;
        location = loc;
        department = "Not Assigned";
        status = "Registered";

        totalComplaints++;
    }

    // Copy Constructor
    Complaint(const Complaint &c)
    {
        complaintId = c.complaintId;
        citizenName = c.citizenName;
        description = c.description;
        location = c.location;
        department = c.department;
        status = c.status;

        totalComplaints++;
    }

    // Virtual Destructor
    virtual ~Complaint()
    {
    }

    int getComplaintId() const
    {
        return complaintId;
    }

    string getStatus() const
    {
        return status;
    }

    string getDepartment() const
    {
        return department;
    }

    void assignDepartment()
    {
        department = getDepartmentName();
        status = "Assigned";
    }

    void updateStatus(string newStatus)
    {
        status = newStatus;
    }

    static int getTotalComplaints()
    {
        return totalComplaints;
    }

    // Pure Virtual Functions
    virtual string getType() const = 0;
    virtual string getPriority() const = 0;
    virtual string getDepartmentName() const = 0;
    virtual void processComplaint() const = 0;

    // Operator Overloading: Compare Complaint ID
    bool operator==(const Complaint &other) const
    {
        return complaintId == other.complaintId;
    }

    // Operator Overloading: Compare Priority
    bool operator>(const Complaint &other) const
    {
        int p1 = getPriorityValue();
        int p2 = other.getPriorityValue();

        return p1 > p2;
    }

    int getPriorityValue() const
    {
        string p = getPriority();

        if (p == "CRITICAL")
            return 4;
        else if (p == "HIGH")
            return 3;
        else if (p == "MEDIUM")
            return 2;
        else
            return 1;
    }

    virtual void display() const
    {
        cout << "\n----------------------------------------";
        cout << "\nComplaint ID : " << complaintId;
        cout << "\nCitizen Name : " << citizenName;
        cout << "\nType         : " << getType();
        cout << "\nDescription  : " << description;
        cout << "\nLocation     : " << location;
        cout << "\nPriority     : " << getPriority();
        cout << "\nDepartment   : " << department;
        cout << "\nStatus       : " << status;
        cout << "\n----------------------------------------\n";
    }
};

int Complaint::totalComplaints = 0;


// ==================== ROAD COMPLAINT ====================
class RoadComplaint : public Complaint
{
public:
    RoadComplaint(int id, string name, string desc, string loc)
        : Complaint(id, name, desc, loc)
    {
    }

    string getType() const
    {
        return "Road Damage";
    }

    string getPriority() const
    {
        return "HIGH";
    }

    string getDepartmentName() const
    {
        return "Road Maintenance Department";
    }

    void processComplaint() const
    {
        cout << "\nProcessing Road Damage Complaint...";
    }
};


// ==================== WATER COMPLAINT ====================
class WaterComplaint : public Complaint
{
public:
    WaterComplaint(int id, string name, string desc, string loc)
        : Complaint(id, name, desc, loc)
    {
    }

    string getType() const
    {
        return "Water Supply";
    }

    string getPriority() const
    {
        return "CRITICAL";
    }

    string getDepartmentName() const
    {
        return "Water Supply Department";
    }

    void processComplaint() const
    {
        cout << "\nProcessing Water Supply Complaint...";
    }
};


// ==================== WASTE COMPLAINT ====================
class WasteComplaint : public Complaint
{
public:
    WasteComplaint(int id, string name, string desc, string loc)
        : Complaint(id, name, desc, loc)
    {
    }

    string getType() const
    {
        return "Waste Management";
    }

    string getPriority() const
    {
        return "MEDIUM";
    }

    string getDepartmentName() const
    {
        return "Sanitation Department";
    }

    void processComplaint() const
    {
        cout << "\nProcessing Waste Management Complaint...";
    }
};


// ==================== DRAINAGE COMPLAINT ====================
class DrainageComplaint : public Complaint
{
public:
    DrainageComplaint(int id, string name, string desc, string loc)
        : Complaint(id, name, desc, loc)
    {
    }

    string getType() const
    {
        return "Drainage Issue";
    }

    string getPriority() const
    {
        return "HIGH";
    }

    string getDepartmentName() const
    {
        return "Drainage Department";
    }

    void processComplaint() const
    {
        cout << "\nProcessing Drainage Complaint...";
    }
};


// ==================== STREETLIGHT COMPLAINT ====================
class StreetlightComplaint : public Complaint
{
public:
    StreetlightComplaint(int id, string name, string desc, string loc)
        : Complaint(id, name, desc, loc)
    {
    }

    string getType() const
    {
        return "Streetlight Issue";
    }

    string getPriority() const
    {
        return "MEDIUM";
    }

    string getDepartmentName() const
    {
        return "Electrical Department";
    }

    void processComplaint() const
    {
        cout << "\nProcessing Streetlight Complaint...";
    }
};


// ==================== MAIN PROGRAM ====================
int main()
{
    const int MAX = 100;

    Complaint *complaints[MAX];

    int complaintCount = 0;
    int choice;

    do
    {
        cout << "\n\n==============================================";
        cout << "\n   URBAN COMPLAINT MANAGEMENT SYSTEM";
        cout << "\n==============================================";

        cout << "\n1. Register Complaint";
        cout << "\n2. Display All Complaints";
        cout << "\n3. Assign Department";
        cout << "\n4. Update Complaint Status";
        cout << "\n5. Track Resolution";
        cout << "\n6. Compare Two Complaints";
        cout << "\n7. Generate Service Performance Report";
        cout << "\n8. Display Statistics";
        cout << "\n9. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (complaintCount >= MAX)
            {
                cout << "\nMaximum complaints reached!";
                break;
            }

            int id, type;
            string name, description, location;

            cout << "\nEnter Complaint ID: ";
            cin >> id;

            cout << "Enter Citizen Name: ";
            cin >> ws;
            getline(cin, name);

            cout << "Enter Description: ";
            getline(cin, description);

            cout << "Enter Location: ";
            getline(cin, location);

            cout << "\nSelect Complaint Type:";
            cout << "\n1. Road Damage";
            cout << "\n2. Water Supply";
            cout << "\n3. Waste Management";
            cout << "\n4. Drainage Issue";
            cout << "\n5. Streetlight Issue";

            cout << "\nEnter type: ";
            cin >> type;

            switch (type)
            {
            case 1:
                complaints[complaintCount] =
                    new RoadComplaint(id, name, description, location);
                break;

            case 2:
                complaints[complaintCount] =
                    new WaterComplaint(id, name, description, location);
                break;

            case 3:
                complaints[complaintCount] =
                    new WasteComplaint(id, name, description, location);
                break;

            case 4:
                complaints[complaintCount] =
                    new DrainageComplaint(id, name, description, location);
                break;

            case 5:
                complaints[complaintCount] =
                    new StreetlightComplaint(id, name, description, location);
                break;

            default:
                cout << "\nInvalid Complaint Type!";
                continue;
            }

            cout << "\nComplaint Registered Successfully!";
            cout << "\nPriority: "
                 << complaints[complaintCount]->getPriority();

            complaints[complaintCount]->processComplaint();

            complaintCount++;
            break;
        }


        case 2:
        {
            if (complaintCount == 0)
            {
                cout << "\nNo complaints available!";
            }
            else
            {
                cout << "\n========== ALL COMPLAINTS ==========\n";

                for (int i = 0; i < complaintCount; i++)
                {
                    complaints[i]->display();
                }
            }

            break;
        }


        case 3:
        {
            int id;
            bool found = false;

            cout << "\nEnter Complaint ID: ";
            cin >> id;

            for (int i = 0; i < complaintCount; i++)
            {
                if (complaints[i]->getComplaintId() == id)
                {
                    complaints[i]->assignDepartment();

                    cout << "\nDepartment Assigned Successfully!";
                    cout << "\nDepartment: "
                         << complaints[i]->getDepartment();

                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "\nComplaint not found!";
            }

            break;
        }


        case 4:
        {
            int id;
            int statusChoice;
            bool found = false;

            cout << "\nEnter Complaint ID: ";
            cin >> id;

            for (int i = 0; i < complaintCount; i++)
            {
                if (complaints[i]->getComplaintId() == id)
                {
                    cout << "\nSelect New Status:";
                    cout << "\n1. Registered";
                    cout << "\n2. Assigned";
                    cout << "\n3. In Progress";
                    cout << "\n4. Resolved";
                    cout << "\n5. Closed";

                    cout << "\nEnter choice: ";
                    cin >> statusChoice;

                    if (statusChoice == 1)
                        complaints[i]->updateStatus("Registered");

                    else if (statusChoice == 2)
                        complaints[i]->updateStatus("Assigned");

                    else if (statusChoice == 3)
                        complaints[i]->updateStatus("In Progress");

                    else if (statusChoice == 4)
                        complaints[i]->updateStatus("Resolved");

                    else if (statusChoice == 5)
                        complaints[i]->updateStatus("Closed");

                    else
                    {
                        cout << "\nInvalid status!";
                        break;
                    }

                    cout << "\nStatus Updated Successfully!";

                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "\nComplaint not found!";
            }

            break;
        }


        case 5:
        {
            int id;
            bool found = false;

            cout << "\nEnter Complaint ID: ";
            cin >> id;

            for (int i = 0; i < complaintCount; i++)
            {
                if (complaints[i]->getComplaintId() == id)
                {
                    cout << "\n========== RESOLUTION TRACKING ==========";
                    complaints[i]->display();

                    if (complaints[i]->getStatus() == "Resolved" ||
                        complaints[i]->getStatus() == "Closed")
                    {
                        cout << "\nComplaint has been resolved.";
                    }
                    else
                    {
                        cout << "\nComplaint is still under processing.";
                    }

                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "\nComplaint not found!";
            }

            break;
        }


        case 6:
        {
            int id1, id2;
            Complaint *c1 = NULL;
            Complaint *c2 = NULL;

            cout << "\nEnter First Complaint ID: ";
            cin >> id1;

            cout << "Enter Second Complaint ID: ";
            cin >> id2;

            for (int i = 0; i < complaintCount; i++)
            {
                if (complaints[i]->getComplaintId() == id1)
                    c1 = complaints[i];

                if (complaints[i]->getComplaintId() == id2)
                    c2 = complaints[i];
            }

            if (c1 == NULL || c2 == NULL)
            {
                cout << "\nOne or both complaints not found!";
            }
            else
            {
                if (*c1 == *c2)
                {
                    cout << "\nBoth complaints have the same ID.";
                }
                else
                {
                    cout << "\nComplaints are different.";

                    if (*c1 > *c2)
                    {
                        cout << "\nComplaint " << id1
                             << " has higher priority.";
                    }
                    else if (*c2 > *c1)
                    {
                        cout << "\nComplaint " << id2
                             << " has higher priority.";
                    }
                    else
                    {
                        cout << "\nBoth complaints have the same priority.";
                    }
                }
            }

            break;
        }


        case 7:
        {
            int resolved = 0;
            int pending = 0;

            int road = 0;
            int water = 0;
            int waste = 0;
            int drainage = 0;
            int streetlight = 0;

            for (int i = 0; i < complaintCount; i++)
            {
                string type = complaints[i]->getType();

                if (type == "Road Damage")
                    road++;

                else if (type == "Water Supply")
                    water++;

                else if (type == "Waste Management")
                    waste++;

                else if (type == "Drainage Issue")
                    drainage++;

                else if (type == "Streetlight Issue")
                    streetlight++;

                if (complaints[i]->getStatus() == "Resolved" ||
                    complaints[i]->getStatus() == "Closed")
                {
                    resolved++;
                }
                else
                {
                    pending++;
                }
            }

            double resolutionRate = 0;

            if (complaintCount > 0)
            {
                resolutionRate =
                    (double)resolved / complaintCount * 100;
            }

            cout << "\n\n========================================";
            cout << "\n      SERVICE PERFORMANCE REPORT";
            cout << "\n========================================";

            cout << "\nTotal Complaints       : "
                 << complaintCount;

            cout << "\nResolved Complaints    : "
                 << resolved;

            cout << "\nPending Complaints     : "
                 << pending;

            cout << "\n\nRoad Complaints        : "
                 << road;

            cout << "\nWater Complaints       : "
                 << water;

            cout << "\nWaste Complaints       : "
                 << waste;

            cout << "\nDrainage Complaints    : "
                 << drainage;

            cout << "\nStreetlight Complaints : "
                 << streetlight;

            cout << "\n\nResolution Rate        : "
                 << resolutionRate << "%";

            cout << "\n========================================";

            break;
        }


        case 8:
        {
            cout << "\n========== SYSTEM STATISTICS ==========";
            cout << "\nTotal Complaints Registered: "
                 << Complaint::getTotalComplaints();

            cout << "\nCurrent Complaints Stored: "
                 << complaintCount;

            break;
        }


        case 9:
        {
            cout << "\nThank you for using the system!";

            for (int i = 0; i < complaintCount; i++)
            {
                delete complaints[i];
            }

            break;
        }


        default:
            cout << "\nInvalid choice! Please try again.";
        }

    } while (choice != 9);

    return 0;
}