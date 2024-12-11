import sys
from scipy.ndimage import gaussian_filter
from PIL import Image
import numpy as np

def apply_gaussian_blur(input_file, output_file, sigma):
    try:
        # Open the PPM image
        image = Image.open(input_file)

        if image.format != "PPM":
            raise ValueError("Input file is not a PPM image.")

        # Convert the image to a NumPy array
        image_array = np.array(image)

        # Apply Gaussian filter to each channel separately
        blurred_array = np.zeros_like(image_array)
        for channel in range(image_array.shape[2]):
            blurred_array[:, :, channel] = gaussian_filter(image_array[:, :, channel], sigma=sigma)

        # Convert the blurred array back to an image
        blurred_image = Image.fromarray(blurred_array, mode="RGB")

        # Save the output image
        blurred_image.save(output_file, format="PPM")
        print(f"Blurred image saved to {output_file}")

    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("Usage: python gaussian_blur.py <input_file.ppm> <output_file.ppm> <sigma>")
        sys.exit(1)

    input_file = sys.argv[1]
    output_file = sys.argv[2]
    sigma = float(sys.argv[3])

    apply_gaussian_blur(input_file, output_file, sigma)

