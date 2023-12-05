/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <algorithm>

class CelestialEvent {
public:
    std::string event;
    std::string date;
};

class CelestialCalendar {
private:
    CelestialEvent events[50];  
    int numEvents;

public:
    CelestialCalendar() : numEvents(0) {}

    void add_event(const CelestialEvent& event) {
        if (numEvents < 50) {
            events[numEvents++] = event;
        }
    }

    void sort_by_date() {
        std::sort(events, events + numEvents,
                  [](const CelestialEvent& a, const CelestialEvent& b) {
                      return a.date < b.date;
                  });
    }

    void find_events_in_month(const std::string& inputMonth) const {
        for (int i = 0; i < numEvents; ++i) {
            if (events[i].date.find(inputMonth) != std::string::npos) {
                std::cout << "Celestial event in " << events[i].date << ": " << events[i].event << std::endl;
            }
        }
    }
};

int main() {
    CelestialCalendar celestialCalendar;


    CelestialEvent celestialEvents[] = {
        {"Quadrantids Meteor Shower", "January 3, 4"},
        {"Full Moon", "January 6"},
        {"New Moon", "January 21"},
        {"Mercury at Greatest Western Elongation", "January 30"},
        {"Full Moon", "February 5"},
        {"New Moon", "February 20"},
        {"Full Moon", "March 7"},
        {"March Equinox", "March 20"},
        {"New Moon", "March 21"},
        {"Full Moon", "April 6"},
        {"Mercury at Greatest Eastern Elongation", "April 11"},
        {"New Moon, Hybrid Solar Eclipse", "April 20"},
        {"Lyrids Meteor Shower", "April 22, 23"},
        {"Full Moon, Penumbral Lunar Eclipse", "May 5"},
        {"Eta Aquarids Meteor Shower", "May 5, 6"},
        {"New Moon", "May 19"},
        {"Mercury at Greatest Western Elongation", "May 29"},
        {"Mars in the Beehive", "June 1, 2"},
        {"Full Moon, Venus at Greatest Eastern Elongation", "June 4"},
        {"Venus in the Beehive", "June 12, 13"},
        {"New Moon", "June 18"},
        {"June Solstice", "June 21"},
        {"Conjunction of Venus and Mars", "July 1"},
        {"Full Moon, Supermoon", "July 3"},
        {"New Moon", "July 17"},
        {"Delta Aquarids Meteor Shower", "July 29, 30"},
        {"Full Moon, Supermoon", "August 1"},
        {"Mercury at Greatest Eastern Elongation", "August 10"},
        {"Perseids Meteor Shower", "August 12, 13"},
        {"New Moon", "August 16"},
        {"Moon Occults Antares", "August 24"},
        {"Saturn at Opposition", "August 27"},
        {"Full Moon, Supermoon, Blue Moon", "August 31"},
        {"New Moon", "September 15"},
        {"Neptune at Opposition", "September 19"},
        {"Mercury at Greatest Western Elongation, September Equinox", "September 22"},
        {"Full Moon, Supermoon", "September 29"},
        {"Draconids Meteor Shower", "October 8, 9"},
        {"New Moon, Annular Solar Eclipse", "October 14"},
        {"Orionids Meteor Shower", "October 20, 21"},
        {"Venus at Greatest Western Elongation", "October 23"},
        {"Full Moon, Partial Lunar Eclipse", "October 28"},
        {"Jupiter at Opposition", "November 3"},
        {"Taurids Meteor Shower", "November 4, 5"},
        {"New Moon, Uranus at Opposition", "November 13"},
        {"Leonids Meteor Shower", "November 17, 18"},
        {"Full Moon", "November 27"},
        {"Mercury at Greatest Eastern Elongation", "December 4"},
        {"New Moon", "December 12"},
        {"Geminids Meteor Shower", "December 13, 14"},
        {"Ursids Meteor Shower, December Solstice", "December 21, 22"},
        {"Full Moon", "December 27"}
    };
    
    int numEvents = sizeof(celestialEvents) / sizeof(celestialEvents[0]);


    for (int i = 0; i < numEvents; ++i) {
        celestialCalendar.add_event(celestialEvents[i]);
    }

  
    celestialCalendar.sort_by_date();

    
    std::string inputMonth;
    std::cout << "Enter a month: ";
    std::cin >> inputMonth;

    celestialCalendar.find_events_in_month(inputMonth);

    return 0;
}
