# ray-tracer

Progress from initial rough output to final polished image: All of the output generated following the code from this tutorial: https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects. Now I have a very high-level overview of what's involved in developing a ray tracer and I'm planning to improve and render different images.

1. **Background gradient**  
   ![Background gradient](png_images/background_gradient.png)

2. **Full scene**  
   ![Full scene](png_images/ray_traced_image.png)

3. **Shading**  
   ![Shading sphere](png_images/shading_sphere.png)

4. **With ground**  
   ![With ground](png_images/with_ground.png)

5. **Antialiasing**  
   ![Antialiasing](png_images/antialiasing.png)

6. **Gray sphere**  
   ![Gray sphere](png_images/gray_sphere.png)

7. **Improved diffusion**  
   ![Improved diffusion](png_images/improved_diffusion.png)

8. **Lambertian diffusion**  
   ![Lambertian diffusion](png_images/lambertian_diffusion.png)

9. **Hollow glass**  
   ![Hollow glass](png_images/hollow_glass.png)

10. **Refracted**  
    ![Refracted](png_images/refracted.png)

11. **Internal reflection**  
    ![Internal reflection](png_images/internal_reflection.png)

12. **Light reflection**  
    ![Light reflection](png_images/light_reflection.png)

13. **Final polished**  
    ![Final polished](png_images/final_image.png)

---

- it's become so clear now that the syntax is not a problem. it found it very easy to understand what's going on in the `vec3.h` file because i know the foundational concept of object-oriented programming and interface. now i see why people say understanding one language well (in my case is Python) can help you grasp other programming languages fairly easily.
- on a high level, a ray tracing consists of these core components:
  - **ray generation**: the camera shoots rays to the pixels of an image. we need to define the position of the camera, where it's looking, and the virtual viewport
  - **ray-scene intersection**: what the ray hits and where
  - **material/shading**: what color it is, how rough, metallic, or transparent -> this is important because it defines how light scatters on the object surface
  - **light transport**: when a ray hits a surface, it doesn't just stop — it spawns new rays. A mirror spawns a reflection ray. Glass spawns a refraction ray. A diffuse surface spawns rays in random directions to gather indirect light from the rest of the scene. This is _recursive_ and is the core of what makes ray tracing look realistic. The number of times a ray is allowed to bounce is called the ray depth.
  - **image reconstruction**: the radiance values collected by all the rays through a pixel need to be combined into a final pixel color by averaging multiple samples/pixel (antialising) -> tone mapping + gamma correction.
