// 页面加载完成后执行
document.addEventListener('DOMContentLoaded', function() {
    // 主页按钮点击事件
    const greetBtn = document.getElementById('greetBtn');
    if (greetBtn) {
        greetBtn.addEventListener('click', function() {
            const name = prompt('What is your name?');
            if (name) {
                alert(`Hello, ${name}! Welcome to my homepage!`);
            } else {
                alert('Hello, stranger! Welcome to my homepage!');
            }
        });
    }

    // 为所有页面的图片添加加载动画
    const images = document.querySelectorAll('img');
    images.forEach(img => {
        img.style.opacity = '0';
        img.style.transition = 'opacity 0.5s';
        img.onload = function() {
            img.style.opacity = '1';
        }
        // 新增：如果图片已经加载完成（如缓存的本地图片），直接显示
        if (img.complete) {
            img.style.opacity = '1';
    }
    });

    // 联系表单提交处理（仅在contact.html生效）
    const contactForm = document.getElementById('contactForm');
    if (contactForm) {
        contactForm.addEventListener('submit', function(e) {
            e.preventDefault(); // 阻止表单默认提交
            const name = document.getElementById('name').value;
            alert(`Thanks, ${name}! Your message has been sent.`);
            contactForm.reset(); // 重置表单
        });
    }
});
