#include <iostream>
using namespace std;

void castVote(int votes[],
              int &totalVotes,
              int voterIDs[],
              int &voterCount)
{
    int voterID;
    int candidateChoice;

    cout << "\nEnter Voter ID: ";
    cin >> voterID;

    if (voterID <= 0)
    {
        cout << "Invalid Voter ID!\n";
        return;
    }

    // Check if voter already voted
    for (int i = 0; i < voterCount; i++)
    {
        if (voterIDs[i] == voterID)
        {
            cout << "You have already voted!\n";
            return;
        }
    }

    cout << "\nCandidates:\n";
    cout << "1. Candidate A\n";
    cout << "2. Candidate B\n";
    cout << "3. Candidate C\n";

    cout << "Enter your vote: ";
    cin >> candidateChoice;

    if (candidateChoice >= 1 && candidateChoice <= 3)
    {
        votes[candidateChoice - 1]++;
        totalVotes++;

        voterIDs[voterCount] = voterID;
        voterCount++;

        cout << "Vote recorded successfully!\n";
    }
    else
    {
        cout << "Invalid Candidate!\n";
    }
}

void showResults(int votes[],
                 char candidate[],
                 int totalVotes)
{
    cout << "\n======== RESULTS ========\n";

    for (int i = 0; i < 3; i++)
    {
        cout << "Candidate "
             << candidate[i]
             << ": "
             << votes[i]
             << " votes\n";
    }

    cout << "\nTotal Votes: "
         << totalVotes
         << endl;
}

void showWinner(int votes[])
{
    if (votes[0] == 0 &&
        votes[1] == 0 &&
        votes[2] == 0)
    {
        cout << "\nNo votes have been cast yet.\n";
        return;
    }

    int maxVotes = votes[0];

    for (int i = 1; i < 3; i++)
    {
        if (votes[i] > maxVotes)
        {
            maxVotes = votes[i];
        }
    }

    int count = 0;

    for (int i = 0; i < 3; i++)
    {
        if (votes[i] == maxVotes)
        {
            count++;
        }
    }

    cout << "\n===== WINNER =====\n";

    if (count == 1)
    {
        for (int i = 0; i < 3; i++)
        {
            if (votes[i] == maxVotes)
            {
                cout << "Candidate "
                     << char('A' + i)
                     << " wins with "
                     << maxVotes
                     << " votes.\n";
            }
        }
    }
    else
    {
        cout << "Tie between ";

        bool first = true;

        for (int i = 0; i < 3; i++)
        {
            if (votes[i] == maxVotes)
            {
                if (!first)
                {
                    cout << " and ";
                }

                cout << "Candidate "
                     << char('A' + i);

                first = false;
            }
        }

        cout << " with "
             << maxVotes
             << " votes.\n";
    }
}

int main()
{
    int choice = 0;
    int totalVotes = 0;

    char candidate[] = {'A', 'B', 'C'};
    int votes[3] = {0, 0, 0};

    int voterIDs[100];
    int voterCount = 0;

    while (choice != 4)
    {
        cout << "\n========= DIGITAL VOTING MACHINE =========\n";
        cout << "1. Cast Vote\n";
        cout << "2. Show Results\n";
        cout << "3. Show Winner\n";
        cout << "4. Exit\n";

        cout << "Enter User Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            castVote(votes,
                     totalVotes,
                     voterIDs,
                     voterCount);
            break;

        case 2:
            showResults(votes,
                        candidate,
                        totalVotes);
            break;

        case 3:
            showWinner(votes);
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }
    }

    return 0;
}