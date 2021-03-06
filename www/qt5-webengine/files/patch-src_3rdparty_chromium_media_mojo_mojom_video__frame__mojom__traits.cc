--- src/3rdparty/chromium/media/mojo/mojom/video_frame_mojom_traits.cc.orig	2020-11-07 01:22:36 UTC
+++ src/3rdparty/chromium/media/mojo/mojom/video_frame_mojom_traits.cc
@@ -20,9 +20,9 @@
 #include "ui/gfx/mojom/buffer_types_mojom_traits.h"
 #include "ui/gfx/mojom/color_space_mojom_traits.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/posix/eintr_wrapper.h"
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 namespace mojo {
 
@@ -62,7 +62,7 @@ media::mojom::VideoFrameDataPtr MakeVideoFrameData(
             std::move(offsets)));
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (input->storage_type() == media::VideoFrame::STORAGE_DMABUFS) {
     std::vector<mojo::PlatformHandle> dmabuf_fds;
 
@@ -165,7 +165,7 @@ bool StructTraits<media::mojom::VideoFrameDataView,
         shared_buffer_data.TakeFrameData(),
         shared_buffer_data.frame_data_size(), std::move(offsets),
         std::move(strides), timestamp);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (data.is_dmabuf_data()) {
     media::mojom::DmabufVideoFrameDataDataView dmabuf_data;
     data.GetDmabufDataDataView(&dmabuf_data);
