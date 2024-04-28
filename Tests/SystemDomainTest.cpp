//
// Created by abdir on 26/04/2024.
//

#include <iostream>
#include <fstream>
#include <gtest/gtest.h>
#include "../Objects/System.h"
#include "../SystemImporter.h"
#include "../Utils.h"


#include <gtest/gtest.h>
#include "../Objects/System.h"

class SystemDomainTest : public ::testing::Test {
protected:
    friend class System;

    virtual void SetUp() {

    }

    virtual void TearDown() {

    }

    System system_;

};


TEST_F(SystemDomainTest, DefaultConstructor) {
    // Checkt of de default constructor van System werkt
    EXPECT_TRUE(system_.properlyInitialized());


}

TEST_F(SystemDomainTest, HappydayScheduler) {

    // Verify that all jobs have been assigned to a device
    // Verify that the jobs have been assigned to the devices with the least workload and emission not over the cap

    Job* job1 =  new Job();
    Device* device1 =  new Device();
    job1->setUserName("user1");
    job1->setPageCount(10);
    job1->setUserName("Peter Selie");
    job1->setType("scan");

    system_.addJob(job1);

    device1->setType("scan");
    device1->setName("device1");
    device1->setEmission(8);
    device1->setSpeed(10);

    system_.addDevice(device1);

    system_.assigning_jobs();


    EXPECT_TRUE(device1->getCurrentJob() == job1);
    EXPECT_EQ(device1->getWorkload(), 10);


}

TEST_F(SystemDomainTest, SystemEmission) {
    Job* job1 =  new Job();
    Device* device1 =  new Device();
    job1->setUserName("user1");
    job1->setPageCount(10);
    job1->setUserName("Peter Selie");
    job1->setType("scan");

    system_.addJob(job1);

    device1->setType("scan");
    device1->setName("device1");
    device1->setEmission(8);
    device1->setSpeed(10);

    system_.addDevice(device1);

    system_.assigning_jobs();

    system_.Do_job_minutes(10);

    EXPECT_EQ(system_.getExejob_CO2(), 80);
}

TEST_F(SystemDomainTest, JobExecution) {
    Job* job1 = new Job();
    job1->setPageCount(10);
    Device* device1 = new Device();
    device1->setSpeed(10);
    system_.addJob(job1);
    system_.addDevice(device1);
    system_.assigning_jobs();
    system_.Do_job_minutes(10);
    EXPECT_TRUE(device1->getCurrentJob() == nullptr);
    EXPECT_EQ(device1->getWorkload(), 0);
}

TEST_F(SystemDomainTest, SystemReset) {
    Job* job1 = new Job();
    Device* device1 = new Device();
    system_.addJob(job1);
    system_.addDevice(device1);
    system_.assigning_jobs();
    system_.clear();
    EXPECT_TRUE(system_.jobs.empty());
    EXPECT_TRUE(system_.devices.empty());
}

TEST_F(SystemDomainTest, ContractViolations) {
    // Check if the contracts are violated




}
