class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
            Ý tưởng chính:
            - Hai mảng nums1 và nums2 đều đã được sắp xếp tăng dần.
            - Ta cần tìm median của hai mảng sau khi gộp lại,
              nhưng không được gộp thật vì cần O(log(m+n)).
            
            Cách làm:
            - Dùng binary search trên mảng nhỏ hơn.
            - Chia hai mảng thành 2 nửa: bên trái và bên phải.
            - Điều kiện đúng của median là:
              
              maxLeft1 <= minRight2
              maxLeft2 <= minRight1

            Khi đó:
            - Mọi phần tử bên trái <= mọi phần tử bên phải.
            - Median nằm ở biên giữa hai nửa.
        */

        // Đảm bảo nums1 luôn là mảng nhỏ hơn để binary search nhanh hơn
        // và tránh trường hợp partition2 bị vượt biên.
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n = nums1.size();
        int m = nums2.size();

        // Binary search số phần tử lấy từ nums1 cho nửa bên trái
        int left = 0;
        int right = n;

        while (left <= right) {
            /*
                partition1:
                - số phần tử của nums1 nằm ở nửa bên trái.

                partition2:
                - số phần tử của nums2 nằm ở nửa bên trái.

                Tổng số phần tử bên trái cần là:
                (m + n + 1) / 2

                Vì sao +1?
                - Nếu tổng số phần tử là lẻ, bên trái sẽ nhiều hơn bên phải 1 phần tử.
                - Khi đó median chính là phần tử lớn nhất bên trái.
            */

            int partition1 = (left + right) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;

            /*
                Sau khi chia:

                nums1:  [ ... maxLeft1 | minRight1 ... ]
                nums2:  [ ... maxLeft2 | minRight2 ... ]

                maxLeft1  = phần tử lớn nhất bên trái nums1
                minRight1 = phần tử nhỏ nhất bên phải nums1

                maxLeft2  = phần tử lớn nhất bên trái nums2
                minRight2 = phần tử nhỏ nhất bên phải nums2
            */

            // Nếu partition1 == 0 nghĩa là bên trái nums1 không có phần tử nào
            // nên dùng INT_MIN để không ảnh hưởng đến phép max.
            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];

            // Nếu partition1 == n nghĩa là bên phải nums1 không có phần tử nào
            // nên dùng INT_MAX để không ảnh hưởng đến phép min.
            int minRight1 = (partition1 == n) ? INT_MAX : nums1[partition1];

            // Tương tự cho nums2
            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == m) ? INT_MAX : nums2[partition2];

            /*
                Kiểm tra xem cách chia hiện tại đã đúng chưa.

                Điều kiện đúng:
                - maxLeft1 <= minRight2
                - maxLeft2 <= minRight1

                Nghĩa là:
                - Phần tử lớn nhất bên trái nums1 không được lớn hơn phần tử nhỏ nhất bên phải nums2.
                - Phần tử lớn nhất bên trái nums2 không được lớn hơn phần tử nhỏ nhất bên phải nums1.

                Nếu cả hai đúng:
                => toàn bộ nửa trái <= toàn bộ nửa phải.
                => tìm được vị trí median.
            */
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                /*
                    Nếu tổng số phần tử là chẵn:
                    median = trung bình cộng của:
                    - phần tử lớn nhất bên trái
                    - phần tử nhỏ nhất bên phải
                */
                if ((m + n) % 2 == 0) {
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                }
                /*
                    Nếu tổng số phần tử là lẻ:
                    bên trái có nhiều hơn bên phải 1 phần tử.
                    median chính là phần tử lớn nhất bên trái.
                */
                else {
                    return max(maxLeft1, maxLeft2);
                }
            }

            /*
                Nếu maxLeft1 > minRight2:

                Nghĩa là:
                - Ta đang lấy quá nhiều phần tử từ nums1 sang bên trái.
                - Phần tử bên trái nums1 quá lớn.
                
                Cần giảm partition1.
                => Dịch binary search sang trái.
            */
            else if (maxLeft1 > minRight2) {
                right = partition1 - 1;
            }

            /*
                Trường hợp còn lại là maxLeft2 > minRight1:

                Nghĩa là:
                - Ta đang lấy quá ít phần tử từ nums1 sang bên trái.
                - Bên phải nums1 còn quá nhỏ, không đủ để cân bằng với nums2.
                
                Cần tăng partition1.
                => Dịch binary search sang phải.
            */
            else {
                left = partition1 + 1;
            }
        }

        // Trường hợp này hầu như không xảy ra nếu input đúng là hai mảng đã sort.
        return 0.0;
    }
};