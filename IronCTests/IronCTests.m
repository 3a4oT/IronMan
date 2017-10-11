//
//  IronCTests.m
//  IronCTests
//
//  Created by Petro Rovenskyy on 10/11/17.
//

#import <XCTest/XCTest.h>
#import "IronCMan.h"

@interface IronCTests : XCTestCase

@end

@implementation IronCTests

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testIronManPower {
    IronCMan cMan;
    initIronCMan(&cMan);
    int minInitialPower;
    
    //Expect 13
    int s[] = { -5, 4, -2, 3, 1, -1, -6, -1, 0, -5}; // => 13
    size_t l = (sizeof(s) / sizeof(s[0]));
    minInitialPower = cMan.minInitialPower(l, s, 1);
    XCTAssertEqual(minInitialPower, 13);
    
    //Expect 18
    int s1[] = { -2, -5, 4, 1, -5, -10 }; //=> 18
    size_t l1 = (sizeof(s1) / sizeof(s1[0]));
    minInitialPower = cMan.minInitialPower(l1, s1, 1);
    XCTAssertEqual(minInitialPower, 18);
    
    //Expect 8
    int s2[] = { -5, 4, -2, 3, 1, -1, -6, -1, 0, 5}; //=> 8
    size_t l2 = (sizeof(s2) / sizeof(s2[0]));
    minInitialPower = cMan.minInitialPower(l2, s2, 1);
    XCTAssertEqual(minInitialPower, 8);
    
    //Expect 3
    int s3[] = {-2, 3, 1, 0, -1}; //=> 3
    size_t l3 = (sizeof(s3) / sizeof(s3[0]));
    minInitialPower = cMan.minInitialPower(l3, s3, 1);
    XCTAssertEqual(minInitialPower, 3);
    
    //Expect 97
    int s4[] = { 100, 3, 1, 0, -200}; //=> 97
    size_t l4 = (sizeof(s4) / sizeof(s4[0]));
    minInitialPower = cMan.minInitialPower(l4, s4, 1);
    XCTAssertEqual(minInitialPower, 97);
    
    //Expect 1
    int s5[] = { 0, 0, 0, 0, 0}; //=> 1
    size_t l5 = (sizeof(s5) / sizeof(s5[0]));
    minInitialPower = cMan.minInitialPower(l5, s5, 1);
    XCTAssertEqual(minInitialPower, 1);
    
    //Expect 5
    int s6[] = { -4, 100}; //=> 5
    size_t l6 = (sizeof(s6) / sizeof(s6[0]));
    minInitialPower = cMan.minInitialPower(l6, s6, 1);
    XCTAssertEqual(minInitialPower, 5);
    
    //Expect 5
    int s7[] = { -3, -1}; //=> 5
    size_t l7 = (sizeof(s7) / sizeof(s7[0]));
    minInitialPower = cMan.minInitialPower(l7, s7, 1);
    XCTAssertEqual(minInitialPower, 5);
    
    //Expect 1
    int s8[] = { -0}; //=> 1
    size_t l8 = (sizeof(s8) / sizeof(s8[0]));
    minInitialPower = cMan.minInitialPower(l8, s8, 1);
    XCTAssertEqual(minInitialPower, 1);
    
    //Clean
    cleanIronCMan(&cMan);
}


@end
