#include "header.h"

#include <bits/stdc++.h>
#include <vector>
#include <random>
#include <windows.h>

using namespace std;
#define INT_MAX 5000000

// vector<vector<int>> distance_matrix = {{INT_MAX, 10, 20, INT_MAX, INT_MAX},
//                                      {10, INT_MAX, 30, 40, INT_MAX},
//                                      {20, 30, INT_MAX, INT_MAX, 50},
//                                      {INT_MAX, 40, INT_MAX, INT_MAX, 60},
//                                      {INT_MAX, INT_MAX, 50, 60, INT_MAX}};

// vector<vector<int>> time_matrix = {{INT_MAX, 5, 20, INT_MAX, INT_MAX},
//                                    {5, INT_MAX, 15, 30, INT_MAX},
//                                    {20, 15, INT_MAX, INT_MAX, 30},
//                                    {INT_MAX, 20, INT_MAX, INT_MAX, 35},
//                                    {INT_MAX, INT_MAX, 30, 35, INT_MAX}};

vector<vector<int> > distance_matrix = {{INT_MAX, INT_MAX, 15, 25, INT_MAX},
                                     {INT_MAX, INT_MAX, 20, INT_MAX, 30},
                                     {15, 20, INT_MAX, INT_MAX, INT_MAX},
                                     {25, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
                                     {INT_MAX, 30, INT_MAX, INT_MAX, INT_MAX}};

vector<vector<int> > time_matrix = {{INT_MAX, INT_MAX, 15, 25, INT_MAX},
                                     {INT_MAX, INT_MAX, 20, INT_MAX, 30},
                                     {15, 20, INT_MAX, INT_MAX, INT_MAX},
                                     {25, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
                                     {INT_MAX, 30, INT_MAX, INT_MAX, INT_MAX}};


/*vector<vector<int>> distance_matrix = {{INT_MAX,12,INT_MAX,5,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
                                    {12,INT_MAX,INT_MAX,INT_MAX,INT_MAX,11,INT_MAX,INT_MAX,INT_MAX,INT_MAX,1,INT_MAX,INT_MAX,INT_MAX},
                                    {INT_MAX,INT_MAX,INT_MAX,6,INT_MAX,INT_MAX,INT_MAX,4,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
                                    {5,INT_MAX,6,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
                                    {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,23,3,INT_MAX,INT_MAX},
                                    {INT_MAX,11,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,19,INT_MAX,INT_MAX,INT_MAX},
                                    {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,15,10,INT_MAX,14,INT_MAX,INT_MAX,16},
                                    {INT_MAX,INT_MAX,4,INT_MAX,INT_MAX,INT_MAX,15,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
                                    {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,10,INT_MAX,INT_MAX,INT_MAX,8,INT_MAX,INT_MAX,INT_MAX},
                                    {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,25,INT_MAX,29,INT_MAX},
                                    {INT_MAX,1,INT_MAX,INT_MAX,23,19,14,INT_MAX,8,25,INT_MAX,17,20,INT_MAX},
                                    {INT_MAX,INT_MAX,INT_MAX,INT_MAX,3,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,17,INT_MAX,INT_MAX,INT_MAX},
                                    {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,29,20,INT_MAX,INT_MAX,INT_MAX},
                                    {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,16,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX}};

vector<vector<int>> time_matrix = {{INT_MAX,12,INT_MAX,5,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
                                    {12,INT_MAX,INT_MAX,INT_MAX,INT_MAX,11,INT_MAX,INT_MAX,INT_MAX,INT_MAX,1,INT_MAX,INT_MAX,INT_MAX},
                                    {INT_MAX,INT_MAX,INT_MAX,6,INT_MAX,INT_MAX,INT_MAX,4,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
                                    {5,INT_MAX,6,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
                                    {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,23,3,INT_MAX,INT_MAX},
                                    {INT_MAX,11,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,19,INT_MAX,INT_MAX,INT_MAX},
                                    {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,15,10,INT_MAX,14,INT_MAX,INT_MAX,16},
                                    {INT_MAX,INT_MAX,4,INT_MAX,INT_MAX,INT_MAX,15,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
                                    {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,10,INT_MAX,INT_MAX,INT_MAX,8,INT_MAX,INT_MAX,INT_MAX},
                                    {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,25,INT_MAX,29,INT_MAX},
                                    {INT_MAX,1,INT_MAX,INT_MAX,23,19,14,INT_MAX,8,25,INT_MAX,17,20,INT_MAX},
                                    {INT_MAX,INT_MAX,INT_MAX,INT_MAX,3,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,17,INT_MAX,INT_MAX,INT_MAX},
                                    {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,29,20,INT_MAX,INT_MAX,INT_MAX},
                                    {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,16,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX}};*/


struct Chromosome {
  vector<int> tour;
  int distance;
  int time;
  int fitness;
};

void normalize() {

    int minDist = INT_MAX;
    int maxDist = INT_MIN;
    int minTime = INT_MAX;
    int maxTime = INT_MIN;
    for(int i=0; i<distance_matrix.size(); i++) {
        for(int j=0; j<distance_matrix.size(); j++) {
            if(minDist > distance_matrix[i][j]) {
                minDist = distance_matrix[i][j];
            }
            if(maxDist < distance_matrix[i][j]) {
                maxDist = distance_matrix[i][j];
            }
            if(minTime > time_matrix[i][j]) {
                minTime = time_matrix[i][j];
            }
            if(maxTime < time_matrix[i][j]) {
                maxTime = time_matrix[i][j];
            }
        }
    }

    //printf("%d %d", minDist, maxDist);

    for(int i=0; i<distance_matrix.size(); i++) {
        for(int j=0; j<distance_matrix.size(); j++) {
            int d1 = (distance_matrix[i][j] - minDist);
            double temp1 = (double)d1 / (maxDist - minDist);
            distance_matrix[i][j] = temp1*5000000;

            int t1 = time_matrix[i][j] - minTime;
            double temp2 = (double)t1 / (maxTime - minTime);

            time_matrix[i][j] = temp2*5000000;

        }
    }

    /*for(int i=0; i<distance_matrix.size(); i++) {
       for(int j=0; j<distance_matrix.size(); j++) {
            printf("%d ", distance_matrix[i][j]);
       }
       printf("\n");
    }*/
}

int calculateDistance(vector<int> tour) {
  int distance = 0;
  for (int i = 0; i < tour.size() - 1; i++) {
    distance += distance_matrix[tour[i]][tour[i + 1]];
  }
  distance += distance_matrix[tour[tour.size() - 1]][tour[0]];
  return distance;
}


int calculateTime(vector<int> tour) {

  int time = 0;
  for (int i = 0; i < tour.size() - 1; i++) {
    time += time_matrix[tour[i]][tour[i + 1]];
  }
  time += time_matrix[tour[tour.size() - 1]][tour[0]];
  return time;
}


Chromosome generateRandomChromosome(int num_cities) {
  Chromosome chromosome;
  chromosome.tour.resize(num_cities);
  for (int i = 0; i < num_cities; i++) {
    chromosome.tour[i] = i;
  }


  random_shuffle(chromosome.tour.begin(), chromosome.tour.end());

  chromosome.distance = calculateDistance(chromosome.tour);
  chromosome.time = calculateTime(chromosome.tour);

  return chromosome;
}


double evaluateFitness(Chromosome chromosome, double dist_wt, double time_wt) {


  double fitness = dist_wt*chromosome.distance + time_wt*chromosome.time;
  return fitness;
}


Chromosome selectChromosomeForCrossover(vector<Chromosome>& chromosomes) {

  int num_chromosomes = chromosomes.size();
  int tournament_size = 5;

  vector<int> tournament_participants(tournament_size);
  for (int i = 0; i < tournament_size; i++) {
    tournament_participants[i] = rand() % num_chromosomes;
  }

  int best_chromosome_index = 0;
  for (int i = 1; i < tournament_size; i++) {
    if (chromosomes[tournament_participants[i]].fitness < chromosomes[best_chromosome_index].fitness) {
      best_chromosome_index = tournament_participants[i];
    }
  }

  // std::cout<< "best fitness: " << chromosomes[best_chromosome_index].fitness << endl;
  return chromosomes[best_chromosome_index];
}

void printTour(vector<int> tour) {
  for(int i=0; i<tour.size(); i++) {
    std::cout<< tour[i]<< " ";
  }
  std::cout<< endl;
}

Chromosome crossover(Chromosome chromosome1, Chromosome chromosome2) {

  Chromosome child_chromosome;
  child_chromosome.tour.resize(chromosome1.tour.size());

  int crossover_point = rand() % chromosome1.tour.size();
  //cout<< "crossover: " << crossover_point;
  for (int i = 0; i < crossover_point; i++) {
    child_chromosome.tour[i] = chromosome1.tour[i];
  }


  set<int> added_cities;
  for (int i = 0; i < crossover_point; i++) {
    added_cities.insert(chromosome1.tour[i]);
  }


  int next_city_index = crossover_point;
  for (int i = 0; i < chromosome1.tour.size(); i++) {
    while (added_cities.count(chromosome2.tour[i]) > 0) {
      i++;
    }
    child_chromosome.tour[next_city_index] = chromosome2.tour[i];
    added_cities.insert(chromosome2.tour[i]);
    next_city_index++;
  }

  ////cout<< "child chromosome: ";
  // printTour(child_chromosome.tour);
  child_chromosome.distance = calculateDistance(child_chromosome.tour);
  child_chromosome.time = calculateTime(child_chromosome.tour);

  return child_chromosome;
}

int MOGA(char places[][50]) {

  int population_size = 1000;
  int num_generations = 10000;

  double dist_wt, time_wt;
  cout << "Enter weight for distance: ";
  cin >> dist_wt;
  cout << "Enter weight for time: ";
  cin >> time_wt;

  normalize();

  vector<Chromosome> chromosomes;
  for (int i = 0; i < population_size; i++) {
    Chromosome generatedCromosome = generateRandomChromosome(distance_matrix.size());
    chromosomes.push_back(generatedCromosome);
  }

  // for(Chromosome c: chromosomes) {
  //   c.fitness = evaluateFitness(c);
  //   printTour(c.tour);
  //   std::cout<< c.fitness << endl;
  // }

  // Sleep(10000);

  // std::cout<< chromosomes.size() <<endl;

  for (int i = 0; i < num_generations; i++) {

    for (int j = 0; j < population_size; j++) {
      chromosomes[j].fitness = evaluateFitness(chromosomes[j], dist_wt, time_wt);
    }


    vector<Chromosome> selected_chromosomes;
    for (int j = 0; j < population_size / 2; j++) {
      Chromosome chromosome1 = selectChromosomeForCrossover(chromosomes);
      Chromosome chromosome2 = selectChromosomeForCrossover(chromosomes);
      selected_chromosomes.push_back(chromosome1);
      selected_chromosomes.push_back(chromosome2);
    }

    vector<Chromosome> offspring_chromosomes;
    for (int j = 0; j < selected_chromosomes.size() - 1; j += 2) {
      Chromosome offspring_chromosome1 = crossover(selected_chromosomes[j], selected_chromosomes[j + 1]);
      Chromosome offspring_chromosome2 = crossover(selected_chromosomes[j + 1], selected_chromosomes[j]);
      offspring_chromosomes.push_back(offspring_chromosome1);
      // cout << "offspring: ";
      // cout<< evaluateFitness(offspring_chromosome1);
      // cout<< "path: " ;
      // printTour(offspring_chromosome1.tour);
      offspring_chromosomes.push_back(offspring_chromosome2);
      // cout << "offspring: ";
      // cout<< evaluateFitness(offspring_chromosome2);
      // cout<< "path: " ;
      // printTour(offspring_chromosome2.tour);
    }

    // std::cout<< "offspring: " << offspring_chromosomes.size() <<endl;
    chromosomes = offspring_chromosomes;
  }

  Chromosome best_chromosome = chromosomes[0];
  for (int i = 1; i < population_size; i++) {
    if (chromosomes[i].fitness < best_chromosome.fitness) {
      best_chromosome = chromosomes[i];
    }
  }
  // std::cout<< "tour: ";
  // for(int a: best_chromosome.tour) {
  //   std::cout<< a << " ";
  // }
  // std::cout<< endl;

  //std::cout << "The best chromosome is:" << best_chromosome.tour.size() << endl;
  for (int i = 0; i < best_chromosome.tour.size(); i++) {
    std::cout << best_chromosome.tour[i] << " ";
    //std::cout << places[best_chromosome.tour[i]] << "\n";
  }
  //std::cout << endl;

  return 0;
}
