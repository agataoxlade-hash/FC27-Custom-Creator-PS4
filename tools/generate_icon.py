from PIL import Image, ImageDraw, ImageFont

img = Image.new("RGB", (512, 512), (10, 16, 30))
d = ImageDraw.Draw(img)
d.rounded_rectangle((24, 24, 488, 488), radius=56, fill=(18, 34, 58), outline=(75, 220, 205), width=8)
d.rounded_rectangle((76, 92, 436, 420), radius=28, fill=(25, 48, 70))
try:
    font_big = ImageFont.truetype("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf", 112)
    font_small = ImageFont.truetype("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf", 42)
except OSError:
    font_big = ImageFont.load_default()
    font_small = ImageFont.load_default()
d.text((112, 145), "FC27", font=font_big, fill=(245, 248, 252), stroke_width=2)
d.text((118, 300), "CREATOR", font=font_small, fill=(75, 220, 205))
img.save("sce_sys/icon0.png", format="PNG")
