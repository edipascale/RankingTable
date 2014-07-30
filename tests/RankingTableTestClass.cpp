/*
 * File:   RankingTableTestClass.cpp
 * Author: dipascae
 *
 * Created on 30-Jul-2014, 12:29:02
 */

#include "RankingTableTestClass.hpp"
#include "../RankingTable.hpp"


CPPUNIT_TEST_SUITE_REGISTRATION(RankingTableTestClass);

RankingTableTestClass::RankingTableTestClass() {
}

RankingTableTestClass::~RankingTableTestClass() {
}

void RankingTableTestClass::setUp() {
}

void RankingTableTestClass::tearDown() {
}

void RankingTableTestClass::testClear() {
  RankingTable<int> rankingTable;
  for (int i = 0; i < 5; i++) 
    rankingTable.insert(i);
  rankingTable.clear();  
  CPPUNIT_ASSERT(rankingTable.size() == 0);
  CPPUNIT_ASSERT(rankingTable.isInCatalog(0) == false);
  
}

void RankingTableTestClass::testErase() {
  int e = 0;
  RankingTable<int> rankingTable;
  rankingTable.erase(e);
  CPPUNIT_ASSERT(rankingTable.size() == 0);
  rankingTable.insert(e);
  rankingTable.erase(e);
  CPPUNIT_ASSERT(rankingTable.size() == 0);
  CPPUNIT_ASSERT(rankingTable.isInCatalog(e) == false);
  rankingTable.insert(e);
  rankingTable.insert(1);
  rankingTable.insert(2);
  for (int i = 0; i < 3; i++)
    rankingTable.hit(1);
  rankingTable.hit(e);
  rankingTable.erase(e);
  CPPUNIT_ASSERT(rankingTable.getRankOf(1) == 0);
  CPPUNIT_ASSERT(rankingTable.getRankOf(2) == 1);
}

void RankingTableTestClass::testEraseByRank() {
  int e = 0;
  RankingTable<int> rankingTable;
  rankingTable.eraseByRank(0);
  CPPUNIT_ASSERT(rankingTable.size() == 0);
  rankingTable.insert(e);
  rankingTable.eraseByRank(0);
  CPPUNIT_ASSERT(rankingTable.size() == 0);
  CPPUNIT_ASSERT(rankingTable.isInCatalog(e) == false);
  rankingTable.insert(e);
  rankingTable.insert(1);
  rankingTable.insert(2);
  for (int i = 0; i < 3; i++)
    rankingTable.hit(1);
  rankingTable.hit(e);
  rankingTable.eraseByRank(1);
  CPPUNIT_ASSERT(rankingTable.getRankOf(1) == 0);
  CPPUNIT_ASSERT(rankingTable.getRankOf(2) == 1);
}

void RankingTableTestClass::testGetElementByRank() {
  uint rank;
  RankingTable<int> rankingTable;
  CPPUNIT_ASSERT_THROW(rankingTable.getElementByRank(rank), int);
  rankingTable.insert(10);
  int result = rankingTable.getElementByRank(0);
  CPPUNIT_ASSERT(result == 10);  
}

void RankingTableTestClass::testGetHits() {
  int e = 1;
  RankingTable<int> rankingTable;
  CPPUNIT_ASSERT_THROW(rankingTable.getHits(e), int);
  rankingTable.insert(e);
  CPPUNIT_ASSERT(rankingTable.getHits(e) == 0);
  rankingTable.hit(e);
  CPPUNIT_ASSERT(rankingTable.getHits(e) == 1);
}

void RankingTableTestClass::testGetHitsByRank() {
  uint rank = 0;
  RankingTable<int> rankingTable;
  CPPUNIT_ASSERT_THROW(rankingTable.getHitsByRank(rank), int);
  rankingTable.insert(1);
  CPPUNIT_ASSERT(rankingTable.getHitsByRank(rank) == 0);
  rankingTable.hit(1);
  CPPUNIT_ASSERT(rankingTable.getHitsByRank(rank) == 1);
}

void RankingTableTestClass::testGetRankOf() {
  int e = 0;
  RankingTable<int> rankingTable;
  CPPUNIT_ASSERT_THROW(rankingTable.getRankOf(e), int);
  rankingTable.insert(e);
  CPPUNIT_ASSERT(rankingTable.getRankOf(e) == 0);  
}

void RankingTableTestClass::testHit() {
  int e = 0;
  RankingTable<int> table;
  CPPUNIT_ASSERT_THROW(table.hit(e), int);
  table.insert(0);
  table.insert(1);
  table.insert(2);
  table.hit(2);
  CPPUNIT_ASSERT(table.getRankOf(2) == 0);
  table.hit(2);
  CPPUNIT_ASSERT(table.getRankOf(2) == 0);
  table.hit(0);
  CPPUNIT_ASSERT(table.getRankOf(0) == 1);  
}

void RankingTableTestClass::testInsert() {
  int e = 0;
  RankingTable<int> rankingTable;
  rankingTable.insert(e);
  CPPUNIT_ASSERT(rankingTable.size() == 1);
  CPPUNIT_ASSERT(rankingTable.isInCatalog(e) == true);
  rankingTable.insert(e);
  CPPUNIT_ASSERT(rankingTable.size() == 1);
  CPPUNIT_ASSERT(rankingTable.isInCatalog(e) == true);
}

void RankingTableTestClass::testIsInCatalog() {
  int e = 0;
  RankingTable<int> rankingTable;
  bool result = rankingTable.isInCatalog(e);
  CPPUNIT_ASSERT(result == false);
  rankingTable.insert(e);
  result = rankingTable.isInCatalog(e);
  CPPUNIT_ASSERT(result == true);
  rankingTable.erase(e);
  result = rankingTable.isInCatalog(e);
  CPPUNIT_ASSERT(result == false);
}

void RankingTableTestClass::testSize() {
  RankingTable<int> rankingTable;
  uint result = rankingTable.size();
  CPPUNIT_ASSERT(result == 0);
  rankingTable.insert(0);
  result = rankingTable.size();
  CPPUNIT_ASSERT(result == 1);
}

