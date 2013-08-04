#include <iostream>
#include <fstream>
#include <list>
#include <vector>

typedef unsigned int base_type;
typedef unsigned long long result_type;
typedef std::list<base_type> astronaut_container_t;
typedef astronaut_container_t::iterator astronaut_container_it;
typedef std::vector<base_type> country_astronaut_count_t;

void record_astronauts(
    base_type idx, astronaut_container_t * astronauts,
    char * visited, base_type & counter)
{
    // Skipe the visited ones
    if(visited[idx]) return;
    
    astronaut_container_t & container = astronauts[idx];
    astronaut_container_it it = container.begin();
    const astronaut_container_it end = container.end();
    
    for(; it != end; ++it)
    {
        record_astronauts(*it, astronauts, visited, counter);
    }
    
    visited[idx] = 1;
    ++counter;
}

result_type number_of_crews(std::istream & istr)
{
    result_type numCrews = 0;
    base_type N, l, idx, astronaut1, astronaut2;
    country_astronaut_count_t astronautsByCountries;
    
    istr >> N >> l;
    
    // Prepare storage
    astronaut_container_t * astronauts = new astronaut_container_t[N];
    char * visited = new char[N];
    memset(visited, 0, N);
    
    // Parse data
    for(idx = 0; idx < l; ++idx)
    {
        istr >> astronaut1 >> astronaut2;
        astronauts[astronaut1].push_back(astronaut2);
        astronauts[astronaut2].push_back(astronaut1);
    }
    
    // Group the astronauts into countries
    for(idx = 0; idx < N; ++idx)
    {
        base_type counter = 0;
        record_astronauts(idx, astronauts, visited, counter);
        astronautsByCountries.push_back(counter);
    }
    
    // Group the astronauts into countries
    for(idx = 0; idx < astronautsByCountries.size(); ++idx)
    {
        printf("[%u] => %u\n", idx, astronautsByCountries[idx]);
    }
    
    // Clean up
    delete[] astronauts;
    delete[] visited;
    
    return numCrews;
}

int main()
{
    //printf("%llu\n", number_of_crews(std::cin));
    std::ifstream istr("/Users/vietlq/projects/viet-github-cpp/hacker-rank-2013-08/02-a-journey-to-the-moon/test01.txt");
    printf("%llu\n", number_of_crews(istr));
    
    return 0;
}
