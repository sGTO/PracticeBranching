// Set Gomez
// cousins.cpp

#include <iostream>
#include <vector>
#include <string>
#include <fstream>


using namespace std;


void main()
{
	const int SIZE = 10000;

	ifstream fin("cousins.in");
	if (fin)
	{
		ofstream fout("cousins.out");
		int numberOfnodes = 0;
		int nodeToFind = 0;

		while (!fin.eof())
		{
			vector<int> nodes(SIZE);
			vector<int> parrents(SIZE);


			fin >> numberOfnodes;
			fin >> nodeToFind;
			// End marker
			if (numberOfnodes == 0 && nodeToFind == 0)
			{
				break;
			}

			for (int i = 0; i < numberOfnodes; i++)
			{
				fin >> nodes[i];
			}

			// Create parrents vector
			int currentParrent = -1;
			if (numberOfnodes > 2)
			{
				for (int i = 0; i < numberOfnodes; i++)
				{
					int j = i + 1;

					if (nodes[j] - nodes[i] == 1)
					{
						parrents[i] = currentParrent;
					}
					else
					{
						parrents[i] = currentParrent;
						currentParrent++;
					}
				}
			}

			for (int i = 0; i < numberOfnodes; i++)
			{
				int cousins = 0;
				int siblings = 0;
				// Node to find cousins for 
				if (nodes[i] == nodeToFind)
				{ 
					// Value at same index in parrents[]
					int valueAtParrent = parrents[i];
					// Count siblins to subtract later
					for (int k = 0; k < numberOfnodes; k++)
					{
						if (parrents[k] == valueAtParrent)
						{
							siblings++;
						}
					}
					// Value in nodes[] from that index				
					int valueAtnodes = nodes[valueAtParrent];
					// Value at that index in parrents[]
					int brothers = parrents[valueAtParrent];

					for (int j = 0; j < numberOfnodes; j++)
					{		
						// Find the brothers of that node and count their children
						if (parrents[j] == brothers)
						{
							int count = j;
							for (int k = 0; k < numberOfnodes; k++)
							{
								if (parrents[k] == count)
								{
									cousins++;
								}
							}
						}
					}
					// Print total of cousins for that node
					int total = cousins - siblings;
					fout << total << endl;	
				}
			}
		}
	}
	else
	{
		cout << "Input file not found." << endl;
	}
}