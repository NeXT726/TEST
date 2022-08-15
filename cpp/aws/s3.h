#pragma once

#include <iostream>
#include <memory>
#include <fstream>

#include <aws/s3/S3Client.h>
#include <aws/core/auth/AWSCredentialsProvider.h>

#include <aws/s3/model/GetObjectRequest.h>
#include <aws/s3/model/HeadObjectRequest.h>
#include <aws/core/Aws.h>

namespace AWSS3{

class S3Client
{
    public:
        std::unique_ptr<Aws::S3::S3Client> client;

        S3Client()
        {
            Aws::IFStream awsKey("/home/jianglind/aws-s3-key", std::ios::in | std::ios::binary);
            std::string access_key;
            getline(awsKey, access_key);
            std::string secret_key;
            getline(awsKey, secret_key);

            set_credit(access_key, secret_key);
            set_cfg();
            client = std::make_unique<Aws::S3::S3Client>(cred, cfg);
        }
        
        void set_credit(std::string access_key, std::string secret_key)
        {
            cred = Aws::Auth::AWSCredentials(access_key, secret_key);
        }

        void set_cfg()
        {
            cfg.endpointOverride = "https://s3.ap-southeast-1.amazonaws.com/";
            cfg.scheme = Aws::Http::Scheme::HTTP;
            cfg.verifySSL = false;
            cfg.region = "ap-southeast-1";
        }


    private:
        Aws::Client::ClientConfiguration cfg;
        Aws::Auth::AWSCredentials cred;
};

}