#pragma once
#include "net_common.h"

namespace olc
{
	namespace net
	{
		// Message Header is sent at the start of all messages. The template allows us
		// to use "enum class" to ensure that the messages are valid at complile time
		template <typename T>
		struct message_header
		{
			T id{};
			uint32_t size = 0;
		};

		template <typename T>
		struct message
		{
			message_header<T> header{};
			std::vector<uint8_t> body;

			// Returns size of entire message packet in bytes
			size_t size() const
			{
				return body.size();
			}

			//Override for std::out compatability - produces friendly description of message
			friend std::ostream& operator << (std::ostream& os, const message<T>& msg)
			{
				os << "ID:" << int(msg.header.id) << " Size:" << msg.header.size;
				return os;
			}

			//Pushes any POD-like data into the message buffer
			template<typename DataType>
			friend message<T>& operator << (message<T>& msg, const DataType& data)
			{
				//Check that the type of data being pushed is trivially copyable
				static_assert(std::is)
			}

		};
	}
}