#include <stdio.h>
#include <string.h>

int contaChars(char *s) {
    int count = 0;
    for (int i = 0; s[i]; i++)
        if (s[i] == 'f' || s[i] == 'l' || s[i] == 't')
            count++;
    return count;
}

char *menorSubstring(char *string) {
    char *menorSub = string;
    int i;

    for (i = 0; i < strlen(string) - 4; i++) {
        if (strncmp(&string[i], menorSub, 5) < 0) {
            menorSub = &string[i];
        }
    }

    return menorSub;
}

int main() {

    char *sequencia1 =
        "NaBTLkfXatyWD3wN5MPqqFwT1QgPXKADAZvGqyORgAH3UQihu4EqaLAsDJlvSHSCROaHns"
        "N0W1n2sk1PBkQ0FNJytlWJoMB0fdZKas2IhCr1SpyPtcMXCH6oAcOASZUaBIrFhJ9NW9Tk"
        "PvKLDSVAo0W5gW9Vo5yF3b4bDrNDK9PWULf6980bSZJivtz6WzNrViWSkwYdJVuB9D96ua"
        "dQD9uPs3tpT8yLEwLqgtYRzCQC36L96MHZ3brBJ6s8XDRC3qvZc00tGb2nl1Cr19N2Ovhr"
        "L0qDbE1kr92kBTv8ezFHCdxdkFUZPT1769yaXHWxrpKxqZdo4G0ovRYKVbhyf98y09oWVC"
        "yaE07nnFH7LDnypMtuS1dtpqjuhRq6xFJbpBURK5mtG1qQCOH9gKujBwGKlJaLjq6WHVQy"
        "ra3jCCRTwiCHIjF1RwTknINau47yS2ePjy0AUag7BiJTjgppoUJN7iAkEwNfxeCUZoH73L"
        "TRexVdbjT8JqPF6CcUJTmFZm9phkPsMHkmQzxRoDWVwSVOXj9g5NdPg05LxdybHhUL0GE9"
        "tlINLZAwmJnCELryci19h7kG3t9HemzUzvi300vgUYLcIihza8EpIptHD0g0IbijtnkYdD"
        "uH1X4qdaGWSFWdNJrCUYtZNQWDhlWqBkIlZHPR5Y2wngUsn2S1kzzLThUTZgGdnMYo4MA5"
        "LMs45pTmtsNd2SholegyboX9U0gVymkLzJUXwTSSVLrBssRNpK3yenQelwDFXHQS52yeTf"
        "935b0CQQUEeACYxR3wgveJqWySKKugU9a8d9tLSqDf6HNQ6rhXeySe32hqwUsEOqLmHLGk"
        "dcnDaRd61zHv7wOCOFdohaO5bI3WyRDkY42KdVm2zubGwMLuWCojx3lAjCmS7vvXfS2sGZ"
        "v8W1TH5wFCuQThz8RjiAWv7TnoUXWGsmXLtTKNjknjIId0VD3sKDsm7NZM7DHCxwac0bgy"
        "gkVcdlMRFcpiGhkKwohBItehqGY5YXjdr3keLhf6giC1";

    printf("Pergunta 1: %d\n", contaChars(sequencia1));

    char *sequencia2 =
        "NY7diLIIWXHRY2HNG0hJXmxRT5eUrnSLV6RNDdIaWI5XhGqhZrWem9Xr9M2RDDjGIsj800"
        "X2s8muvjCPKWx4yUqK8QKq3DXyQQnW5bvp1GL7dTZ3sPYEcFFdr8kV5kJ2TAVaQzMDDAN1"
        "f23egBN1hDqXLFQwcwddJf1tKhe5RwvteyEpKQF4F8TOkO28UIj6GqE1aGb739Lp4IoxB7"
        "7EAeNc5oeB4k11oanSHWXUmqZOXTC8MGFhljHwTTWgyMco9ZAbdQSp5XRWibTEJC9Z4Rbb"
        "4wEISvQToRNFXCXo1MYaiVa26xeZDULLkaVZNVCKS3lqNbEH9ZnN2IpW5cx0PX8oWB8n7d"
        "opXna7w2TXaU1t7lsMe7QXoFdXvCWJ7XUC97ePJP8X3WUXnwYT3K7pWTlbINLKXgTKUIdm"
        "42DvI1IqgVddOTKJwceeBw5WXqlzitizzYVq9Cqlk9nzVR7qfwvuROrYUEW5gCB6pkitPI"
        "UGFYmECbv1l2vr8iyffiIjIK9o2TxDFOopJwbLtZsryDRgscnDv6bqvjgcGlkHXffel315"
        "6kJHPZHPBoJL9EzboM0FBBelqn7Mrnr56sDNOgDAmryDR4l2UZ0xqOeZFLFovRMXo3NKV2"
        "4GHvNKw1ZPaoAAQlF2rwNBxRTY3iY5LdcxsB0VSPMadtSTn6xOjlzlatR8Gy8cizwdqBJ9"
        "w5SXaC5BolvTh1gY8F3DHt43iNzQgdoEUGssjul7a5HmQ4AwuMBOLwbsuNhKzYAJkNSHaR"
        "PH3Kp0irzVVRDnyeKzYk9Uzt5RnZYtGhKvoK7OKnGRznzT0DibTQTLIAPduRnrkmtfAKtt"
        "rmyLFpSPjR9B6dTAJP8vOqe1b2Ylcqjz3eiUeUh80t1SIrL8ZW92LksOqrY3Ge1qIYLcTz"
        "VC2quzoh95xX2NmWiQSUBHOJfAeqSnPPbxHZfyW0GkfKGyAGtal05pD8xbSUbSFFOVCrnV"
        "1bDqnlww1Nu889cwIRKj2g2KzJBR9I4ZD0ukUT8OylkC";

    printf("Pergunta 2: %.5s\n", menorSubstring(sequencia2));

    return 0;
}