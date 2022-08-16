
#include "s3.h"
#include <aws/s3/model/Bucket.h>
#include <aws/s3/model/ListObjectsRequest.h>
#include <aws/s3/model/GetObjectRequest.h>



using namespace Aws;

std::shared_ptr<AWSS3::S3Client> S3Client;

const Vector<S3::Model::Bucket>& GetBucketsInS3()
{
    auto outcome = S3Client->client->ListBuckets();
    if (outcome.IsSuccess()) {
        std::cout << "Found " << outcome.GetResult().GetBuckets().size() << " buckets\n";
        // for (auto&& b : outcome.GetResult().GetBuckets()) {
        //     std::cout << b.GetName() << std::endl;
        // }
        return outcome.GetResult().GetBuckets();
    }
    else {
        std::cout << "Failed with error: " << outcome.GetError() << std::endl;
        return Vector<S3::Model::Bucket>();
    }
}

Vector<S3::Model::Object> GetObjectsInBucket(String Bucket)
{
    S3::Model::ListObjectsRequest req;
    req.SetBucket(Bucket);
    auto outcome = S3Client->client->ListObjects(req);
    if (outcome.IsSuccess())
    {
        Vector<S3::Model::Object> objects =
            outcome.GetResult().GetContents();
        // for (S3::Model::Object& object : objects)
        // {
        //     std::cout << object.GetKey() << std::endl;
        // }
        return objects;
    }
    else 
    {
        std::cout << "Error: ListObjects: " <<
            outcome.GetError().GetMessage() << std::endl;
        
        return Vector<S3::Model::Object>();
    }
}

bool DownloadObject(String bucket, String key, std::string output_file = "")
{
    Aws::S3::Model::GetObjectRequest req;
    req.SetBucket(bucket);
    req.SetKey(key);

    Aws::S3::Model::GetObjectOutcome outcome = 
        S3Client->client->GetObject(req);

    if(outcome.IsSuccess() && output_file.empty())
    {
        auto& retrieved_file = outcome.GetResultWithOwnership().GetBody();

        std::cout << "Beginning of file contents:\n";
        char file_data[255] = { 0 };
        while(retrieved_file.getline(file_data, 254)){
            std::cout << file_data << std::endl;
        }
        return true;
    }
    else if(outcome.IsSuccess() && !output_file.empty())
    {
        auto& retrieved_file = outcome.GetResultWithOwnership().GetBody();
        retrieved_file.seekg(0, std::ios::beg);

        OFStream outfile(output_file, std::ios::out | std::ios::binary);

        char file_data[255] = {0};
        while(!retrieved_file.eof()){
            retrieved_file.read(file_data, 255);
            size_t read_bytes = retrieved_file.gcount();
            std::cout << "[Downloading][read_bytes:" << read_bytes << "]" << std::endl;
            outfile.write(file_data, read_bytes);
        }
        outfile.close();
        return true;
    }
    else
    {
        auto err = outcome.GetError();
        std::cout << "Error: GetObject: " <<
            err.GetExceptionName() << ": " << err.GetMessage() << std::endl;
        return false;
    }
}


int test()
{
    // test GetBucketsInS3()
    auto Buckets = GetBucketsInS3();

    // test GetObjectsInBucket()
    for (auto&& B : Buckets)
    {
        std::cout << B.GetName() << " hava objects:" << std::endl;
        Vector<S3::Model::Object> objs = GetObjectsInBucket(B.GetName());
        for (S3::Model::Object& object : objs)
        {
            std::cout << object.GetKey() << std::endl;
        }
    }

    // test DownloadObject()
    DownloadObject("moqi", "djlTest/aws-100MB.xml"); // print
    DownloadObject("moqi", "djlTest/aws-100MB.xml", "./djltest"); // Download

    return true;
}

int main()
{
    SDKOptions options;
    options.loggingOptions.logLevel = Utils::Logging::LogLevel::Off;
    
    //The AWS SDK for C++ must be initialized by calling Aws::InitAPI.
    InitAPI(options); 
    {  
        S3Client = std::make_shared<AWSS3::S3Client>();
        DownloadObject("moqi", "djlTest/aws-100MB.xml"); // print
    }

    //Before the application terminates, the SDK must be shut down. 
    ShutdownAPI(options);
    return 0;
}


