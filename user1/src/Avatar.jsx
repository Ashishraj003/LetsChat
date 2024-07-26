export default function Avatar({ username, userId, online }) {
    const colors = ['bg-blue-300', 'bg-yellow-300', 'bg-green-300',
        'bg-teal-300', 'bg-purple-300', 'bg-red-300'];
    const userIdBase10 = parseInt(userId, 16);
    const colorIndex = userIdBase10 % colors.length;
    const color = colors[colorIndex];
    return (
        <div className={"w-8 h-8 relative rounded-full flex items-center " + color}>
            <div className="text-center w-full">{username[0]}</div>
            {online &&
                (
                    <div className="absolute w-3 h-3 bg-green-500 bottom-0 right-0 rounded-full border border-white"></div>
                )
            }
            {!online &&
                (
                    <div className="absolute w-3 h-3 bg-gray-400 bottom-0 right-0 rounded-full border border-white"></div>
                )
            }
        </div>
    );
}