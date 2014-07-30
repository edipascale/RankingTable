/*
 * File:   RankingTableTestClass.hpp
 * Author: Emanuele Di Pascale, CTVR - Trinity College Dublin.
 *
 * Created on 30-Jul-2014, 12:29:01
 */

#ifndef RANKINGTABLETESTCLASS_HPP
#define	RANKINGTABLETESTCLASS_HPP

#include <cppunit/extensions/HelperMacros.h>

class RankingTableTestClass : public CPPUNIT_NS::TestFixture {
  CPPUNIT_TEST_SUITE(RankingTableTestClass);

  CPPUNIT_TEST(testInsert);
  CPPUNIT_TEST(testSize);
  CPPUNIT_TEST(testClear);
  CPPUNIT_TEST(testHit);
  CPPUNIT_TEST(testGetElementByRank);
  CPPUNIT_TEST(testGetHits);
  CPPUNIT_TEST(testGetHitsByRank);
  CPPUNIT_TEST(testGetRankOf);  
  CPPUNIT_TEST(testIsInCatalog);
  CPPUNIT_TEST(testErase);
  CPPUNIT_TEST(testEraseByRank);

  CPPUNIT_TEST_SUITE_END();

public:
  RankingTableTestClass();
  virtual ~RankingTableTestClass();
  void setUp();
  void tearDown();

private:
  void testClear();
  void testErase();
  void testEraseByRank();
  void testGetElementByRank();
  void testGetHits();
  void testGetHitsByRank();
  void testGetRankOf();
  void testHit();
  void testInsert();
  void testIsInCatalog();
  void testSize();

};

#endif	/* RANKINGTABLETESTCLASS_HPP */

